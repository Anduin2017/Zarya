
interface IService
{
public:
  IService(){};
  virtual ~IService(){};

  virtual IService *GetNextService() = 0;
  virtual void SetNextService(IService * NewService) = 0;

  virtual IService *InsertService(IService * NewService) = 0;
  virtual void Run() = 0;

  virtual IService *UseStartUp(IApplicationServer * Server) = 0;
  virtual IService *UseServer(IService * Server) = 0;
};