#include <bits/stdc++.h>
using namespace std;

class DocumentElement
{
public:
  virtual string render() = 0;  // Pure virtual function for rendering the element
  virtual ~DocumentElement() {} // Virtual destructor
};

class TextElement : public DocumentElement
{
private:
  string text;

public:
  TextElement(string text)
  {
    this->text = text; // Initialize the text element with the provided text
  }
  string render() override
  {
    return text; // Render the text element
  }
};
class ImageElement : public DocumentElement
{
private:
  string imagePath;

public:
  ImageElement(string path)
  {
    this->imagePath = path; // Initialize the image element with the provided image path
  }
  string render() override
  {
    return "[img src='" + imagePath + "']"; // Render the image element as an HTML img tag
  }
};
class newlineElement : public DocumentElement
{
public:
  string render() override
  {
    return "\n"; // Render a newline element
  }
};
class tabElement : public DocumentElement
{
public:
  string render() override
  {
    return "\t"; // Render a tab element
  }
};

class Document
{
private:
  vector<DocumentElement *> elements; // Vector to store pointers to document elements
public:
  void addElement(DocumentElement *element)
  {
    elements.push_back(element); // Add a new element to the document
  }
  vector<DocumentElement *> getElements()
  {
    return elements; // Return the vector of document elements
  }
  ~Document()
  {
    for (auto element : elements)
    {
      delete element; // Clean up dynamically allocated elements
    }
  }
};
class DocumentRenderer
{
private:
  Document *document; // Pointer to the document to be rendered
public:
  DocumentRenderer(Document *doc)
  {
    this->document = doc; // Initialize the renderer with the provided document
  }
  string render()
  {
    string renderedContent; // String to hold the rendered content
    for (auto element : document->getElements())
    {
      renderedContent += element->render() + "\n"; // Render each element and append to the content
    }
    return renderedContent; // Return the complete rendered content
  }
};

class Persistence
{
public:
  virtual void save(string data) = 0;
};

class FilePersistence : public Persistence
{
public:
  void save(string data) override
  {
    ofstream outFile("document.txt"); // Open a file to save the document content
    if (outFile.is_open())
    {
      outFile << data; // Write the data to the file
      outFile.close(); // Close the file after writing
    }
    else
    {
      cerr << "Unable to open file for saving." << endl; // Handle file opening errors
    }
  }
};

class DatabasePersistence : public Persistence
{
public:
  void save(string data) override
  {
    // Simulate saving to a database (for demonstration purposes)
    cout << "Saving to database: " << data << endl; // Print the data to be saved to the database
  }
};

class Documenteditor
{
private:
  Document *document; // Pointer to the document being edited
public:
  Documenteditor(Document *doc)
  {
    this->document = doc; // Initialize the editor with the provided document
  }
  void addText(string text)
  {
    document->addElement(new TextElement(text)); // Add a new text element to the document
  }
  void addImage(string imagePath)
  {
    document->addElement(new ImageElement(imagePath)); // Add a new image element to the document
  }
  void addnewline()
  {
    document->addElement(new newlineElement()); // Add a newline element to the document
  }
  void addtab()
  {
    document->addElement(new tabElement()); // Add a tab element to the document
  }
};

class client {
private:
  Documenteditor *editor; // Pointer to the document editor for editing the document
  Persistence *persistence; // Pointer to the persistence mechanism for saving the document
  DocumentRenderer *renderer; // Pointer to the renderer for rendering the document
public:
  client(Documenteditor *editor, Persistence *persistence, DocumentRenderer *renderer)
  {
    this->editor = editor; // Initialize the client with the provided editor
    this->persistence = persistence; // Initialize the client with the provided persistence mechanism
    this->renderer = renderer; // Initialize the client with the provided renderer
  }
  void createDocument()
  {
    editor->addText("Hello, World!"); // Add a text element to the document
    editor->addnewline(); // Add a newline element to the document
    editor->addImage("path/to/image.jpg"); // Add an image element to the document
    editor->addtab(); // Add a tab element to the document
    editor->addText("This is a mini project."); // Add another text element to the document

    string renderedContent = renderer->render(); // Render the document content
    cout << "Rendered Document:\n" << renderedContent; // Print the rendered content

    persistence->save(renderedContent); // Save the rendered content using the persistence mechanism
  }
};

int main()
{
  Document *doc = new Document(); // Create a new document
  Documenteditor *editor = new Documenteditor(doc); // Create a document editor for the document
  DocumentRenderer *renderer = new DocumentRenderer(doc); // Create a renderer for the document
  Persistence *persistence = new FilePersistence(); // Create a file persistence mechanism

  client *myClient = new client(editor, persistence, renderer); // Create a client with the editor, persistence, and renderer
  myClient->createDocument(); // Create and save the document

  delete myClient; // Clean up dynamically allocated client
  delete persistence; // Clean up dynamically allocated persistence
  delete renderer; // Clean up dynamically allocated renderer
  delete editor; // Clean up dynamically allocated editor
  delete doc; // Clean up dynamically allocated document

  return 0; // Exit the program
}