ApplicationBuilder::ApplicationBuilder()
{
}
ApplicationBuilder::~ApplicationBuilder()
{
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
    std::cout << "UseStaticFiles Middleware now added to your app!" << std::endl;
    return this;
}

IApplicationBuilder *ApplicationBuilder::Use404Page()
{
    this->UseMiddleware(new _404Middleware());
    std::cout << "Use404Page Middleware now added to your app!" << std::endl;
    return this;
}

IApplicationBuilder *ApplicationBuilder::UseMVC()
{
    this->UseMiddleware(new MVCMiddleware());
    std::cout << "UseMVCMiddleware Middleware now added to your app!" << std::endl;
    return this;
}

void ApplicationBuilder::OnMessage(HTTPContext *context)
{
    this->NextMiddleware->OnMessage(context);
}