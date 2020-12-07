$wslapi = &{
$wsldll = @'
[DllImport("wslapi.dll", CharSet = CharSet.Ansi)]
public static extern bool WslIsDistributionRegistered(
    [MarshalAs(UnmanagedType.LPWStr)]string distributionName);

[DllImport("wslapi.dll", CharSet = CharSet.Ansi)]
public static extern uint WslUnregisterDistribution(
    [MarshalAs(UnmanagedType.LPWStr)]string distributionName);

[DllImport("wslapi.dll", CharSet = CharSet.Ansi)]
public static extern uint WslRegisterDistribution(
    [MarshalAs(UnmanagedType.LPWStr)]string distributionName,
    [MarshalAs(UnmanagedType.LPWStr)]string tarGzFilename);

[DllImport("wslapi.dll", CharSet = CharSet.Ansi)]
public static extern uint WslConfigureDistribution(
    [MarshalAs(UnmanagedType.LPWStr)]string distributionName,
    ulong defaultUID,
    int wslDistributionFlags);

[DllImport("wslapi.dll", CharSet = CharSet.Ansi)]
public static extern uint WslGetDistributionConfiguration(
    [MarshalAs(UnmanagedType.LPWStr)]string distributionName,
    out ulong distributionVersion,
    out ulong defaultUID,
    out uint wslDistributionFlags,
    out string defaultEnvironmentVariables,
    out uint defaultEnvironmentVariableCount);

[DllImport("wslapi.dll", CharSet = CharSet.Ansi)]
public static extern uint WslLaunchInteractive(
    [MarshalAs(UnmanagedType.LPWStr)]string distributionName,
    [MarshalAs(UnmanagedType.LPWStr)]string command,
    [MarshalAs(UnmanagedType.U1)]bool useCurrentWorkingDirectory,
    out uint exitCode);
'@
return Add-Type -MemberDefinition $wsldll -Name "wslapi" -PassThru
}