# driver.ps1 — fuzz a solution against brute.cpp on random trees.
# Usage:
#   .\driver.ps1                    # tests sol.cpp
#   .\driver.ps1 sol_broken.cpp     # sabotage check: MUST report a mismatch
#
# PowerShell gotchas handled here:
#   - '&&' isn't supported: chain with ';' and check $?.
#   - '<' stdin redirection is reserved: we run redirected commands via cmd /c.
#   - PowerShell '>' writes UTF-16+BOM: cmd /c writes raw bytes, so use it for
#     '>' too, otherwise the .exe's read garbage.

param([string]$sol = "sol.cpp")
$ErrorActionPreference = "Stop"

g++ -O2 -std=c++17 -o gen.exe   gen.cpp   ; if (-not $?) { exit 1 }
g++ -O2 -std=c++17 -o brute.exe brute.cpp ; if (-not $?) { exit 1 }
g++ -O2 -std=c++17 -o sol.exe   $sol      ; if (-not $?) { exit 1 }

for ($seed = 1; $seed -le 2000; $seed++) {
    cmd /c ".\gen.exe $seed > in.txt"
    cmd /c ".\brute.exe < in.txt > b.txt"
    cmd /c ".\sol.exe < in.txt > s.txt"

    $b = (Get-Content b.txt -Raw).Trim()
    $s = (Get-Content s.txt -Raw).Trim()
    if ($b -ne $s) {
        Write-Host "MISMATCH on seed $seed" -ForegroundColor Red
        Write-Host "--- input ---"; Get-Content in.txt
        Write-Host "--- brute ---"; Write-Host $b
        Write-Host "--- yours ---"; Write-Host $s
        exit 1
    }
}
Write-Host "all seeds passed" -ForegroundColor Green