class ZaryaServer : public HostBuilder, implements IApplicationServer //implements IService
{
private:
  int port;
  IApplicationBuilder *middlewares;

public:
  ZaryaServer(int port);
  ~ZaryaServer();
  void Run();

  void GiveMiddlewares(IApplicationBuilder *middlewares);
};
