$mem = New-Object -TypeName 'System.Collections.Generic.List[byte[]]'
while ($true) {
    $block = New-Object byte[] 100MB
    $mem.Add($block)
    Start-Sleep -Milliseconds 1000
}