for /f "tokens=* usebackq" %a in (`^WHERE /R C:\\"Program Files" wordpad.exe`) do set var=%a
%var% R CMD BATCH test.R
pause