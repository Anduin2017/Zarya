interface IApplicationServer
{
public:
  IApplicationServer(){};
  virtual ~IApplicationServer(){};

  virtual void GiveMiddlewares(IApplicationBuilder* middlewares)=0;
};