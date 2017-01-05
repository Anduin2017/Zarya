StartUp::StartUp(IApplicationServer *Server)
{
    this->Server = Server;
}
StartUp::~StartUp()
{
    delete this->Middlewares;
}

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
    app ->UseMVC()
        ->UseDefaultPage()
        ->UseStaticFiles()
        ->Use404Page();
}