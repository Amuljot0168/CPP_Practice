#include <bits/stdc++.h>
using namespace std;

// class command
class Command
{
public:
    string name;
    int duration;

    Command(string name, int duration) : name(name), duration(duration) {}
};

// CommandNode class
class CommandNode
{
public:
    Command *cmd;
    CommandNode *next;

    CommandNode(Command *cmd)
    {
        this->cmd = cmd;
        this->next = nullptr;
    }
};

// Command Executor Class
class CommandExecutor
{
public:
    void run(Command &c)
    {
        cout << "Running command: " << c.name << " Duration: " << c.duration << " secs" << endl;
    }
};

// move to next command
void advanceQueue(CommandNode *&current)
{
    if (current)
    {
        current = current->next;
    }
}

// Print queue function
void printQueue(CommandNode *head)
{
    cout << "The Queue is : ";
    while (head)
    {
        cout << head->cmd->name << " " << head->cmd->duration << " secs | ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

class CommandQueue
{
private:
    CommandNode *head;

public:
    CommandQueue() : head(nullptr) {}

    // Enqueue function
    void enqueue(Command *c)
    {
        if (head == nullptr)
        {
            head = new CommandNode(c);
            return;
        }

        CommandNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new CommandNode(c);
    }

    // Function to execute a command
    void executeNext(CommandNode *&current)
    {
        if (current != nullptr)
        {
            CommandExecutor executor;
            executor.run(*(current->cmd));
            advanceQueue(current);
        }
    }

    // function to execute all commands
    void executeAll()
    {
        CommandNode *temp = head;
        while (temp != nullptr)
        {
            executeNext(temp);
        }
    }

    // function to manage memory
    void clear()
    {
        CommandNode *temp = head;
        while (temp)
        {
            CommandNode *nextNode = temp->next;
            delete temp->cmd;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }

    // return head
    CommandNode *queueHead() { return head; }

    // Destructor calling clear function for memory management
    ~CommandQueue() { clear(); }
};

int main()
{

    CommandQueue queue;

    // Creating commands dynamically
    Command *c1 = new Command("Start Motor", 100);
    Command *c2 = new Command("Open Valve", 50);
    Command *c3 = new Command("Stop Motor", 80);
    Command *c4 = new Command("Start Motor 2", 40);
    Command *c5 = new Command("Stop Motor 2", 120);

    // Enqueue the commands
    queue.enqueue(c1);
    queue.enqueue(c2);
    queue.enqueue(c3);
    queue.enqueue(c4);
    queue.enqueue(c5);

    // print queue
    printQueue(queue.queueHead());

    // Execute all commands
    queue.executeAll();
    return 0;
}