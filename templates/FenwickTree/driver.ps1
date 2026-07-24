param(
    [string]$Sol  = "sol.cpp",  # solution under test (multitest format)
    [int]   $T    = 2000,       # number of testcases in the batch
    [int]   $Base = 1           # base seed
)

$ErrorActionPreference = "Stop"

# --- compile gen, brute, and the solution under test ---
cmd /c "g++ -O2 -std=c++17 gen.cpp -o gen.exe"
if ($?) { cmd /c "g++ -O2 -std=c++17 brute.cpp -o brute.exe" }
if ($?) {
    $solExe = [System.IO.Path]::GetFileNameWithoutExtension($Sol) + ".exe"
    cmd /c "g++ -O2 -std=c++17 $Sol -o $solExe"
}
if (-not $?) { Write-Host "COMPILE FAILED" -ForegroundColor Red; exit 1 }

# --- ONE batched run: gen -> brute -> sol, 3 processes total ---
Write-Host "Compiled. Generating $T testcases (base seed $Base) and comparing..."
cmd /c ".\gen.exe $Base $T 0 > in.txt"
Write-Host "Generated $T testcases (base seed $Base)"
cmd /c ".\brute.exe < in.txt > out_brute.txt"
Write-Host "Solved $T testcases (base seed $Base) via brute force"
cmd /c ".\$solExe < in.txt > out_sol.txt"
Write-Host "Solved $T testcases (base seed $Base) by your solution"

if ((Get-Content out_brute.txt -Raw) -eq (Get-Content out_sol.txt -Raw)) {
    Write-Host "ALL $T TESTCASES PASSED for $Sol" -ForegroundColor Green
    exit 0
}

# --- failure only: localize the first offending case, one seed at a time ---
Write-Host "MISMATCH in batch. Localizing the smallest failing case..." -ForegroundColor Yellow
for ($c = 0; $c -lt $T; $c++) {
    cmd /c ".\gen.exe $Base 1 $c > single.txt"
    cmd /c ".\brute.exe < single.txt > sb.txt"
    cmd /c ".\$solExe < single.txt > ss.txt"
    if ((Get-Content sb.txt -Raw) -ne (Get-Content ss.txt -Raw)) {
        Write-Host "FIRST FAILING CASE: index $c  (seed $($Base + $c))" -ForegroundColor Red
        Write-Host "--- input (single.txt, note leading '1' = T) ---"; Get-Content single.txt
        Write-Host "--- expected (brute) ---"; Get-Content sb.txt
        Write-Host "--- got ($Sol) ---";       Get-Content ss.txt
        exit 1
    }
}

# Batch differed but every isolated case passes => state leaking between cases.
Write-Host "Batch differs but no single case reproduces it -> you're not resetting the BIT between testcases in $Sol." -ForegroundColor Yellow
exit 1
