#include "./Headers/Dependencies.h"

using namespace std;



int main()
{
    ZaryaServer *zaryaServer = new ZaryaServer(9000);
    HostBuilder *host = new HostBuilder();

    host->UseStartUp(zaryaServer)
        ->UseServer(zaryaServer)
        ->Run();

    return 0;
}
