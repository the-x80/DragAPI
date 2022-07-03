#include "HTML.h"

DragAPI::HTML::HTMLDocument::HTMLDocument():
	documentNode(nullptr)
{
}

DragAPI::HTML::HTMLDocument::HTMLDocument(HTMLDocument& other):
	documentNode(other.documentNode)
{
}

DragAPI::HTML::HTMLDocument::HTMLDocument(HTMLDocument&& other):
	documentNode(other.documentNode)
{
	other.documentNode = nullptr;
}

DragAPI::HTML::HTMLDocument::~HTMLDocument()
{
	if (this->documentNode != nullptr) {
		delete this->documentNode;
	}
}

void DragAPI::HTML::HTMLDocument::Load(const char* text)
{
	//Perform sanity checks on the string

	//If everything is okay create a document object
	this->documentNode = new HTMLDocumentNode();
}

void DragAPI::HTML::HTMLDocument::LoadFromFile(const char* fName)
{

	char* cstr_FileData = nullptr;


	this->Load(cstr_FileData);

	delete[] cstr_FileData;
	return;
}
