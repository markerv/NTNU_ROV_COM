
#pragma once


namespace janusxsdm
{
    class janus
    {
        static std::string mIP, JPATH, SPATH;
        static int RX_PORT, TX_PORT;
        static uint8_t SDM_FRAMEHEADER[];
    public:
        //Constructor, takes IPV4 of acoustic modem, paths to janus and sdmsh executables and ports to reserve for janus encoding/decoding
        janus(std::string modemIP, std::string JANUSPATH, std::string SDMPATH, int rxPort, int txPort);

        //Setting correct config on sdm
        static int sdmconf();

        //Encodes message to janus in a buffer
        static int sendSimple(std::string message);

        //Untested: Decodes a buffered janus message
        static int decode(int16_t buf[], std::string &message);

        //Simplified sdm listener, will break if communication is incomplete or missing
        static int listenSimple(std::string &message);

        static int printheader();
    };
}