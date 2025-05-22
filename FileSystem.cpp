#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// Definition for a Trie Node which is used internally in FileSystem.
class TrieNode 
{
public:
    std::string name; // Name of the file or directory
    bool isFile; // Flag indicating whether it is a file or not
    std::string content; // Content of the file if it is a file
    std::unordered_map<std::string, TrieNode*> children; // Child nodes, representing files and directories

    // Constructor
    TrieNode() : isFile(false), name("") {}

    // Destructor to clean up dynamic allocations.
    ~TrieNode() 
    {
        for (auto child : children) 
        {
            delete child.second;
        }
    }

    // Method to insert a node and return the last node in the path. Creates intermediate directories as needed.
    TrieNode* insert(const std::string& path, bool fileStatus) 
    {
        TrieNode* node = this;
        size_t prevPos = 1; // Start iterating the path from the character following the initial '/'
        size_t currentPos = path.find('/', prevPos);

        while (currentPos != std::string::npos) 
        {
            std::string part = path.substr(prevPos, currentPos - prevPos);
            if (!node->children.count(part)) 
            {
                node->children[part] = new TrieNode(); // If child does not exist, create it
            }
            node = node->children[part];
            prevPos = currentPos + 1;
            currentPos = path.find('/', prevPos);
        }

        // handle the last part of the path
        std::string part = path.substr(prevPos);
        if (!node->children.count(part)) 
        {
            node->children[part] = new TrieNode(); // If child does not exist, create it
        }
        node = node->children[part];

        node->isFile = fileStatus;
        if (fileStatus) 
        {
            node->name = part; // Set the name of the file
        }

        return node;
    }

    // Method to search for a node given a path.
    TrieNode* search(const std::string& path) 
    {
        TrieNode* node = this;
        size_t prevPos = 1; // Start iterating the path from the character following the initial '/'
        size_t currentPos = path.find('/', prevPos);

        while (currentPos != std::string::npos) 
        {
            std::string part = path.substr(prevPos, currentPos - prevPos);
            if (!node->children.count(part)) 
            {
                return nullptr; // Node not found
            }
            node = node->children[part];
            prevPos = currentPos + 1;
            currentPos = path.find('/', prevPos);
        }

        // Handle the last part of the path
        std::string part = path.substr(prevPos);
        if (!node->children.count(part)) 
        {
            return nullptr; // Node not found
        }
        return node->children[part]; // Node found
    }
};

// Definition of a FileSystem that uses a TrieNode structure to manage files and directories.
class FileSystem 
{
private:
    TrieNode* root; // Root directory of the file system

public:
    // Constructor for the FileSystem
    FileSystem() 
    {
        root = new TrieNode(); // Initialize root
    }

    // Destructor to clean up dynamic allocations.
    ~FileSystem() 
    {
        delete root;
    }

    // List the contents in a directory or return the file if it's just a single file.
    std::vector<std::string> ls(const std::string& path) 
    {
        std::vector<std::string> result;
        TrieNode* node = root->search(path);
        if (!node) 
        {
            return result; // Empty vector if path not found
        }

        if (node->isFile) 
        {
            // If it's a file, add the file name to the result list
            result.push_back(node->name);
        } 
        else 
        {
            // If it's a directory, add all the child names to the list
            for (auto& child : node->children) 
            {
                result.push_back(child.first);
            }
        }
        std::sort(result.begin(), result.end()); // Sort the list lexicographically
        return result;
    }

    // Make a directory given a path.
    void mkdir(const std::string& path) 
    {
        root->insert(path, false);
    }

    // Add content to the file, create the file if it does not exist.
    void addContentToFile(const std::string& filePath, const std::string& content) 
    {
        TrieNode* node = root->insert(filePath, true);
        node->content += content; // Append the content to the file's content
    }

    // Read content from a file.
    std::string readContentFromFile(const std::string& filePath) 
    {
        TrieNode* node = root->search(filePath);
        if (node && node->isFile) 
        {
            return node->content; // Return file content as a String
        }
        return ""; // Return empty String if file does not exist or if it's a directory
    }
};