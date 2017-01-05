#include "./Headers/Dependencies.h"

using namespace std;



int main()
{
    SombraServer *sombraServer = new SombraServer(9000);
    HostBuilder *host = new HostBuilder();

    host->UseStartUp(sombraServer)
        ->UseServer(sombraServer)
        ->Run();

    return 0;
}