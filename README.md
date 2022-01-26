# NTNU_ROV_COM
## Det som står her dukker opp på repoen

##Manual Test Instructions
End all messages to device with the line feed command (\n)
IP is specified in Factory Certificate
Default socket is 9200

Establish connection with:
nc MODEM_IP MODEM_SOCKET

Then:
+++AT?S

Response should be:
+++INITIATION LISTEN <Pool Size>

###Link
Type +++ to enter command mode
Response should be OK

Source Level (Trans Gain)
AT!L3   Lowest setting
AT!L2
AT!L1
AT!L0   Highest setting

High-power air transmission can damage the device!EvoLogics warranty does not cover these damages!

AT&W    saves settings

Type AT0 to enter data mode
Now you are free to transmitt data

Try +++AT?S
Expecting Response ONLINE

Send AT?E    To get input signal level.
Send AT?I   To get signal integrity level.
Send AT?BR  To get remote-to-local bitrate.
Send AT?BL   To get local-to-remote bitrate.


ATD     Establish acoustinc conn
ATHn    Close an acoustic connection n=(0 or 1)(Gracefully or Violent)
AT&V: Get current settings
AT?G and AT!Gn: Gain
    0   Normal gain, corresponds to high sensitivity.
    1   Low gain, corresponds to -20dB reduced sensitivity. Recommended for short distances or testing purposes.

AT?C and AT!Cn: Carrier Waveform ID
0-1 for testing
2-2 or 3-3 ideal for networking

AT?AL and AT!ALn: Local Address
AT?AR and AT!ARn: Remote Address

Markus har gjort en god jobb