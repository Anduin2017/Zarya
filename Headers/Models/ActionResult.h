class ActionResult : implements IActionResult
{
  private:
    char* _result;

  public:
    ActionResult(char* ResponseMessage);
    ~ActionResult();

    char* GetResult();
    void SetResult(char* result);
};