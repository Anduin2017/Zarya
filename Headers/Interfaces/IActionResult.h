
interface IActionResult
{
public:
  IActionResult(){};
  virtual ~IActionResult(){};

  virtual void SetResult(char* result) = 0;
  virtual char* GetResult() = 0;
};