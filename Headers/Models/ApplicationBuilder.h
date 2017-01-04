class ApplicationBuilder : implements IApplicationBuilder
{
private:
public:
  ApplicationBuilder();
  ~ApplicationBuilder();
  IApplicationBuilder *UseMiddleware(IApplicationBuilder* NewMiddleware);

  IApplicationBuilder *UseStaticFiles();
  IApplicationBuilder *Use404Page();
  IApplicationBuilder *UseMVC();

  IActionResult *ExcuteResult(HTTPContext *context);
  void OnMessage(HTTPContext *context);
  bool Excuteable(HTTPContext *context);
};