class SombraServer : public HostBuilder, implements IApplicationServer //implements IService
{
private:
  int port;
  IApplicationBuilder *middlewares;

public:
  SombraServer(int port);
  ~SombraServer();
  void Run();

  void GiveMiddlewares(IApplicationBuilder *middlewares);
};
