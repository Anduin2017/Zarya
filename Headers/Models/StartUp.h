class StartUp : public HostBuilder
{
  private:
    IApplicationServer* Server;
    IApplicationBuilder* Middlewares;
  public:
    StartUp(IApplicationServer* Server);
    ~StartUp();
    void Run();
    void Configure(IApplicationBuilder* app);
};
