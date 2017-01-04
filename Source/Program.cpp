#include "../Headers/Dependencies.h"

using namespace std;

void StartUp::Run()
{
    HostBuilder::Run();
    this->Middlewares = new ApplicationBuilder();
    this->Configure(this->Middlewares);
    this->Server->GiveMiddlewares(this->Middlewares);

    std::cout << "Application Finished Configuration!" << std::endl;
}

void StartUp::Configure(IApplicationBuilder *app)
{
    app->UseMVC()
        ->UseStaticFiles()
        ->Use404Page();
}

int main()
{
    SombraServer *sombraServer = new SombraServer(9000);
    HostBuilder *host = new HostBuilder();

    host->UseStartUp(sombraServer)
        ->UseServer(sombraServer)
        ->Run();

    return 0;
}