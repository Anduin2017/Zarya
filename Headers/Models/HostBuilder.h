class HostBuilder : implements IService
{
private:
  IService *NextService;

public:
  HostBuilder();
  ~HostBuilder();

  IService *GetNextService();
  void SetNextService(IService *NewService);

  IService *InsertService(IService *NewService);
  void Run();

  IService *UseStartUp(IApplicationServer *Server);
  IService *UseServer(IService *Server);
};