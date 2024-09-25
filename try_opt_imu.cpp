#include <iostream>
#include <Eigen/Core>
#include <ceres/ceres.h>
using namespace std;

static std::vector<std::string> split(std::string str, const char* pattern)
{
  std::string::size_type pos;
  std::vector<std::string> result;
  str += pattern;//扩展字符串以方便操作
  long unsigned int size = (unsigned int)str.size();

  for (long unsigned int i = 0; i < size; i++)
  {
    pos = str.find(pattern, i);
    if (pos < size)
    {
      std::string s = str.substr(i, pos - i);
      result.push_back(s);
      i = (unsigned long)(pos);
    }
  }
  return result;
}

int main()
{
  const int LINE_MAX_SIZE = 1024;
  //string line;
  char line[LINE_MAX_SIZE];
  vector<string> lines;
  FILE * fp = fopen("./broker-01.txt", "r");
  bool begin_flag= false;
  while (!feof(fp))
  {
    //fscanf(fp, "%[^\n]", line);
    fgets(line, LINE_MAX_SIZE, fp);
    lines.push_back(string(line));
    //catch (CMemoryException* e)
    //{
    //	
    //}
    //catch (CFileException* e)
    //{
    //}
    //catch (CException* e)
    //{
    //}
    

    //cout << lines[lines.size() - 1] << endl;
    //getchar();
  }
  for (auto line:lines)
  {

    auto words = split(line, " ");
    //cout << words.size() << "   " << line << endl;

    //getchar();

    if (words.size() == 38) begin_flag = true;
    if (begin_flag)
    {
      if (!((words.size() == 38) || (words.size() == 27)))
      {
      cout << words.size()<< "   " << line << endl;

      getchar();

      }

    }

  }

  fclose(fp);

    std::cout << "Hello World!\n";
}
