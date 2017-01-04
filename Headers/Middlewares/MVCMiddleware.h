class MVCMiddleware : public ApplicationBuilder
{
  private:
  public:
    MVCMiddleware();
    ~MVCMiddleware();

  void OnMessage(HTTPContext* context);
};