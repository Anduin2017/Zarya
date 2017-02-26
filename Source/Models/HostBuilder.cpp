HostBuilder::HostBuilder() {}
HostBuilder::~HostBuilder() {}

IService *HostBuilder::GetNextService()
{
    return this->NextService;
}
void HostBuilder::SetNextService(IService *NewService)
{
    this->NextService = NewService;
}

IService *HostBuilder::InsertService(IService *NewService)
{
    NewService->SetNextService(this->NextService);
    this->NextService = NewService;
    return this;
}
void HostBuilder::Run()
{
    if (this->NextService != NULL)
    {
	    this->NextService->Run();
    }
}
IService *HostBuilder::UseStartUp(IApplicationServer* Server)
{
    return this->InsertService(new StartUp(Server));
}

IService *HostBuilder::UseServer(IService* Server)
{
    return this->InsertService(Server);
}