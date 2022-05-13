
#pragma once


namespace janusxsdm
{
    class connection
    {
    private:
        std::string mIP, JPATH, SPATH;
        int RX_PORT, TX_PORT;
        static uint8_t SDM_FRAMEHEADER[];
    public:
        //Constructor, takes IPV4 of acoustic modem, paths to janus and sdmsh executables and ports to reserve for janus encoding/decoding
        connection(std::string modemIP, std::string JANUSPATH, std::string SDMPATH, int rxPort, int txPort);

        //Setting correct config on sdm
        int sdmconf();

        //Sets the correct preamble for janus-data
        int setPreamble();

        //Encodes message to janus in a buffer
        void sendSimple(std::string message);

        //Does not work.. the idea is that you can call this funtion with a binary buffer and get the message payload
        int decode(int16_t buf[], std::string &message);

        //Simplified sdm listener, will break if communication is incomplete or missing
        int listenSimple(std::string &message);

        //Listener that stops blocking after timeout
        int listen(std::string &message, std::chrono::duration<double> timeout);

        //Begining of an atempt to a direct com with the modem
        int printheader();

        //Does nothing for now
        int sdmStop();
    };
}