ApplicationBuilder::ApplicationBuilder()
{
}
ApplicationBuilder::~ApplicationBuilder()
{
    delete this->NextMiddleware;
}

IApplicationBuilder *ApplicationBuilder::UseMiddleware(IApplicationBuilder *NewMiddleware)
{
    IApplicationBuilder *Pointer = this;
    while (Pointer->NextMiddleware != NULL)
    {
        Pointer = Pointer->NextMiddleware;
    }
    Pointer->NextMiddleware = NewMiddleware;
}

IApplicationBuilder *ApplicationBuilder::UseStaticFiles()
{
    this->UseMiddleware(new StaticFilesMiddleware());
    std::cout << "StaticFilesMiddleware\t Middleware now added to your app!" << std::endl;
    return this;
}

IApplicationBuilder *ApplicationBuilder::Use404Page()
{
    this->UseMiddleware(new _404Middleware());
    std::cout << "_404Middleware\t\t Middleware now added to your app!" << std::endl;
    return this;
}

IApplicationBuilder *ApplicationBuilder::UseMVC()
{
    this->UseMiddleware(new MVCMiddleware());
    std::cout << "MVCMiddleware\t\t Middleware now added to your app!" << std::endl;
    return this;
}

IApplicationBuilder *ApplicationBuilder::UseDefaultPage()
{
    this->UseMiddleware(new DefaultPageMiddleware());
    std::cout << "DefaultPageMiddleware\t Middleware now added to your app!" << std::endl;
    return this;
}

void ApplicationBuilder::OnMessage(HTTPContext *context)
{
    this->NextMiddleware->OnMessage(context);
}