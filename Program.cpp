#include "./Headers/Dependencies.h"

using namespace std;



int main()
{
    ZaryaServer *ZaryaServer = new ZaryaServer(9000);
    HostBuilder *host = new HostBuilder();

    host->UseStartUp(ZaryaServer)
        ->UseServer(ZaryaServer)
        ->Run();

    return 0;
}