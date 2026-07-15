# driver.ps1
# PowerShell 5.1-safe stress-test driver.
# Usage: .\driver.ps1 [-N 1000]
#
# Compiles gen.cpp, brute.cpp, and sol.cpp, then runs N random cases,
# comparing sol.exe's output against the brute.exe oracle. Stops and
# prints the seed + failing input on the first mismatch.
#
# All stdin/stdout redirection goes through cmd /c "..." -- native
# PowerShell redirection (< / >) mangles arguments and writes UTF-16 with
# a BOM, which the C++ programs won't parse correctly.

param(
    [int]$N = 1000
)

$ErrorActionPreference = "Stop"

Write-Host "Compiling gen.cpp..."
g++ -O2 -std=c++17 -o gen.exe gen.cpp
if ($?) {
    Write-Host "Compiling brute.cpp..."
    g++ -O2 -std=c++17 -o brute.exe brute.cpp
    if ($?) {
        Write-Host "Compiling sol.cpp..."
        g++ -O2 -std=c++17 -o sol.exe sol.cpp
        if ($?) {
            Write-Host "Compiles OK. Running $N stress iterations..."

            $failed = $false

            for ($i = 1; $i -le $N; $i++) {
                $seed = $i

                cmd /c "gen.exe $seed > case.txt"
                if ($LASTEXITCODE -ne 0) {
                    Write-Host "gen.exe crashed at seed $seed (exit $LASTEXITCODE)"
                    $failed = $true
                    break
                }

                cmd /c "brute.exe < case.txt > brute_out.txt"
                if ($LASTEXITCODE -ne 0) {
                    Write-Host "brute.exe crashed at seed $seed (exit $LASTEXITCODE)"
                    $failed = $true
                    break
                }

                cmd /c "sol.exe < case.txt > sol_out.txt"
                if ($LASTEXITCODE -ne 0) {
                    Write-Host "sol.exe crashed at seed $seed (exit $LASTEXITCODE)"
                    $failed = $true
                    break
                }

                $expected = (Get-Content brute_out.txt -Raw)
                $got = (Get-Content sol_out.txt -Raw)
                if ($null -eq $expected) { $expected = "" }
                if ($null -eq $got) { $got = "" }
                $expected = $expected.Trim()
                $got = $got.Trim()

                if ($expected -ne $got) {
                    Write-Host ""
                    Write-Host "=== MISMATCH at seed $seed ==="
                    Write-Host "---- input (case.txt) ----"
                    Get-Content case.txt | Write-Host
                    Write-Host "---- expected (brute.exe) ----"
                    Write-Host $expected
                    Write-Host "---- got (sol.exe) ----"
                    Write-Host $got
                    $failed = $true
                    break
                }
            }

            if (-not $failed) {
                Write-Host ""
                Write-Host "All $N tests passed."
            } else {
                exit 1
            }
        } else {
            Write-Host "sol.cpp failed to compile."
            exit 1
        }
    } else {
        Write-Host "brute.cpp failed to compile."
        exit 1
    }
} else {
    Write-Host "gen.cpp failed to compile."
    exit 1
}
