$mem = New-Object -TypeName 'System.Collections.Generic.List[byte[]]'
while ($true) {
    $block = New-Object byte[] 1000MB
    $mem.Add($block)
    Start-Sleep -Milliseconds 300
}