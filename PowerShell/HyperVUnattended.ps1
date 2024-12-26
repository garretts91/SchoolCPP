# Define Variables
$ISOPath = "X:\ISO\Win10.iso"
$MountPath = "C:\Mount"
$UnattendFile = "C:\AnswerFiles\unattend.xml"
$WinImagePath = "C:\Source\install.wim"
$OutputDir = "C:\OutputISO"
$BootImagePath = "C:\Source\boot.wim"
$OSIndex = 1  # Adjust for specific Windows edition
$VMName = "AutoDeployVM"
$VHDPath = "C:\VMs\$VMName\VirtualHardDisk.vhdx"
$VMPath = "C:\VMs\$VMName"

# Create Output Directory
if (-Not (Test-Path $OutputDir)) {
    New-Item -ItemType Directory -Path $OutputDir
}

# Mount Windows Image
if (-Not (Test-Path $MountPath)) {
    New-Item -ItemType Directory -Path $MountPath
}
Mount-WindowsImage -ImagePath $WinImagePath -Index $OSIndex -Path $MountPath

# Copy Unattended Answer File
Copy-Item $UnattendFile "$MountPath\Windows\Panther\unattend.xml"

# Dismount Windows Image and Commit Changes
Dismount-WindowsImage -Path $MountPath -Save

# Copy Boot Files
xcopy $BootImagePath "$OutputDir\boot.wim" /h /y
xcopy $WinImagePath "$OutputDir\install.wim" /h /y

# Create Bootable ISO
$ISOCommand = @(
    'oscdimg',
    '-u2',
    '-b"C:\Source\boot\etfsboot.com"',
    'C:\OutputISO',
    $ISOPath
)
Start-Process -NoNewWindow -Wait -FilePath cmd.exe -ArgumentList "/c", $ISOCommand -PassThru

Write-Host "Bootable ISO created at: $ISOPath"

# Create VM in Hyper-V
if (-Not (Test-Path $VMPath)) {
    New-Item -ItemType Directory -Path $VMPath
}
New-VHD -Path $VHDPath -SizeBytes 20GB -Dynamic
New-VM -Name $VMName -MemoryStartupBytes 8GB -Generation 2 -Path $VMPath -NewVHDPath $VHDPath -SwitchName "Default Switch"
Set-VMFirmware -VMName $VMName -FirstBootDevice (New-VMFirmwareBootDevice -Device BootFromFile -Path $ISOPath)
Add-VMDvdDrive -VMName $VMName -Path $ISOPath
Start-VM -Name $VMName

Write-Host "VM $VMName created and booted with ISO."
