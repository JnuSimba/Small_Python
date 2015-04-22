#include "py_execute.h"

static PyObject* m_LocalEnvironment;
static string m_Command;
static const char* info = "********** Small Python **********\n";
static const char* prompt = ">>> ";

static bool IsSourceAllDigit(string& source)
{
    string::size_type len = source.size();
    for(int i = 0; i < len; i++)
    {
        if (source.at(i) > '9' || source.at(i) < '0')
            return false;
    }

    return true;
}


static PyObject* GetObjectBySymbol(const string& symbol)
{
    PyObject* key = PyStrCreate(symbol.c_str());
    PyObject* value = PyDict_GetItem(m_LocalEnvironment, key);
    if (value == NULL)
    {
        cout << "[Error] : " << symbol << " is not defined!" << endl;
        return NULL;
    }

    delete key;
    return value;
}

// a = 1
// b = 2
// c = a + b
// print c
//
// s1 = "simba"
// s2 = "python"
// s3 = s1 + s2
// print s3
static void ExecuteAdd(string& target, string& source)
{
    string::size_type pos;
    PyObject* intValue = NULL;
    PyObject* strValue = NULL;
    PyObject* resultValue = NULL;
    if (IsSourceAllDigit(source))
    {
        intValue  = PyIntCreate(atoi(source.c_str()));
        PyObject* key = PyStrCreate(target.c_str());
        PyDict_SetItem(m_LocalEnvironment, key, intValue);
        delete key;
    }
    else if (source.find("\"") != string::npos)
    {
        // exclude ""
        strValue = PyStrCreate(source.substr(1, source.size()-2).c_str());
        PyObject* key = PyStrCreate(target.c_str());
        PyDict_SetItem(m_LocalEnvironment, key, strValue);
        delete key;
    }
    else if ((pos = source.find("+")) != string::npos)
    {
        PyObject* leftObject = GetObjectBySymbol(source.substr(0, pos-1));
        PyObject* rightObject = GetObjectBySymbol(source.substr(pos + 2));
        if (leftObject != NULL && rightObject != NULL &&
                leftObject->type == rightObject->type)
        {
            resultValue = (leftObject->type)->add(leftObject, rightObject);
            PyObject* key = PyStrCreate(target.c_str());
            PyDict_SetItem(m_LocalEnvironment, key, resultValue);
            delete key;
        }
        (m_LocalEnvironment->type)->print(m_LocalEnvironment);
    }
}


static void ExecutePrint(string symbol)
{
    PyObject* object = GetObjectBySymbol(symbol);
    if (object != NULL)
    {
        PyTypeObject* type = object->type;
        type->print(object);
    }
}

static void ExecuteCommand(string& command)
{
    string::size_type pos = 0;
    if ((pos = command.find("print ")) != string::npos)
    {
        ExecutePrint(command.substr(6));
    }
    else if ((pos = command.find(" = ")) != string::npos)
    {
        string target = command.substr(0, pos);
        string source = command.substr(pos + 3);
        ExecuteAdd(target, source);
    }
    else
    {
        printf("unsupported command!\n");
    }
}

void ExecutePython(void)
{
    m_LocalEnvironment = PyDictCreate();

    cout << info;
    cout << prompt;
    while (getline(cin, m_Command))
    {
        if (m_Command.size() == 0)
        {
            cout << prompt;
            continue;
        }
        else if (m_Command == "exit")
        {
            Dealloc_Dict(m_LocalEnvironment);
            delete m_LocalEnvironment;
            return ;
        }
        else
        {
            ExecuteCommand(m_Command);
        }
        cout << prompt;
    }
}    


