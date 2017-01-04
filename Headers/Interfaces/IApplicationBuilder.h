
interface IApplicationBuilder
{
public:
  IApplicationBuilder(){};
  virtual ~IApplicationBuilder(){};
  IApplicationBuilder *NextMiddleware;
  virtual IApplicationBuilder *UseMiddleware(IApplicationBuilder* NewMiddleware) = 0;

  virtual IApplicationBuilder *UseStaticFiles() = 0;
  virtual IApplicationBuilder *Use404Page() = 0;
  virtual IApplicationBuilder *UseMVC() = 0;

  //virtual IActionResult *ExcuteResult(HTTPContext * context) = 0;
  virtual void OnMessage(HTTPContext * context) = 0;
  //virtual bool Excuteable(HTTPContext * context) = 0;
};