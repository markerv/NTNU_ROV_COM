
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

        //Sets the correct preamble for janus-data
        static int setPreamble();

        //Encodes message to janus in a buffer
        void sendSimple(std::string message);

        //Does not work.. the idea is that you can call this funtion with a binary buffer and get the message payload
        static int decode(int16_t buf[], std::string &message);

        //Simplified sdm listener, will break if communication is incomplete or missing
        static int listenSimple(std::string &message);

        //Listener that stops blocking after timeout
        static int listen(std::string &message, std::chrono::duration<double> timeout);

        //Begining of an atempt to a direct com with the modem
        static int printheader();

        //Does nothing for now
        static int sdmStop();
    };
}