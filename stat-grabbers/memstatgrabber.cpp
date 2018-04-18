#include "memstatgrabber.h"

MemStatGrabber::MemStatGrabber() : StatGrabber()
{
    stat_files.push_back(std::ifstream(meminfo));
}


void MemStatGrabber::Parse()
{
    std::ifstream& f = stat_files[meminfo_ind];
    if (!f.is_open())
        throw "can't open file";

    map<string,string> stat{{"MemTotal", GetStat("MemTotal", f)},
                            {"AnonPages", GetStat("AnonPages", f)},
                            {"Dirty", GetStat("Dirty", f)},
                            {"MemFree", GetStat("MemFree", f)},
                            {"MemAvailable", GetStat("MemAvailable", f)},
                            {"Cached", GetStat("Cached", f)},
                            {"SwapCached", GetStat("SwapCached", f)},
                            {"Buffers", GetStat("Buffers", f)},
                            {"SwapTotal", GetStat("SwapTotal", f)},
                            {"SwapFree", GetStat("SwapFree", f)},};

    stat_data.push_back(new MemStatisticData(stat));
}


std::string MemStatGrabber::GetStat(const std::string& param_name, std::ifstream& f)
{
    std::string token;

    while(f>>token)
    {
        if(token == param_name+":")
        {
            std::string param_val;
            if(f>>param_val)
            {
                f.seekg(0);
                return param_val;
            }
            else
            {
                f.seekg(0);
                return "0";
            }
        }
    }

    f.seekg(0);
    return "0";
}
