SombraServer::SombraServer(int port)
{
    this->port = port;
}
SombraServer::~SombraServer()
{
}

void read_til_crnl(FILE *fp)
{
    char buf[BUFSIZ];
    while (fgets(buf, BUFSIZ, fp) != NULL && strcmp(buf, "\r\n") != 0)
        ;
}

void SombraServer::Run()
{
    HostBuilder::Run();
    std::cout << "Server Starting at: http://localhost:" << port << "/" << std::endl;

    int sock, SocketId;
    FILE *fpin;
    char request[BUFSIZ];

    sock = make_server_socket(port);
    while (1)
    {
        SocketId = accept(sock, NULL, NULL);
        fpin = fdopen(SocketId, "r");
        fgets(request, BUFSIZ, fpin);
        read_til_crnl(fpin);

        char cmd[BUFSIZ], arg[BUFSIZ];
        strcpy(arg, "./wwwroot");
        if (sscanf(request, "%s%s", cmd, arg + 9) != 2)
        {
            std::cout << "[???]Not A Request!" << std::endl;
        }
        else
        {
            FILE *fp = fdopen(SocketId, "w");
            HTTPContext *context = new HTTPContext();
            context->fp = fp;
            context->Path = arg;
            this->middlewares->OnMessage(context);
        }
        fclose(fpin);
    }
    return;
}

void SombraServer::GiveMiddlewares(IApplicationBuilder *middlewares)
{
    this->middlewares = middlewares;
}
