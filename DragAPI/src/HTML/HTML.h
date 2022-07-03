#pragma once
#ifndef DRAG_API_HTML_H
#define DRAG_API_HTML_H

#include <string>
#include <array>
#include <vector>

#include "../Exceptions/Exceptions.h"
#include "../IO/IO.h"
#include "../Text/Text.h"

namespace DragAPI {
	namespace HTML {
		namespace Exceptions {

		}
	}
	namespace CSS {
		class CSSDocument : public DragAPI::Text::TextDocument {
		private:
		protected:
		public:

		};
	}
	namespace HTML {
		class HTMLAttribute {
		private:
			std::string name;
			std::string value;
		};
		class HTMLNode {
		private:
		protected:
			std::vector<HTMLNode> childNodes;
			std::vector<HTMLAttribute> attributes;

			std::string innerText;
			std::string outerText;
		public:
			HTMLNode();
			HTMLNode(HTMLNode& other);
			HTMLNode(HTMLNode&& other);
			~HTMLNode();



			void Parse(const char* text);
		};
		class HTMLDocumentNode : public HTMLNode {
		private:
		protected:
		public:
			HTMLDocumentNode();
			HTMLDocumentNode(HTMLDocumentNode& other);
			HTMLDocumentNode(HTMLDocumentNode&& other);
			~HTMLDocumentNode();
		};
		class HTMLDocument : public DragAPI::Text::TextDocument {
		private:
			HTMLDocumentNode* documentNode;
		private:
			HTMLDocument();
			HTMLDocument(HTMLDocument& other);
			HTMLDocument(HTMLDocument&& other);
			~HTMLDocument();


			void Load(const char* text);
			void LoadFromFile(const char* fName);
		};
	}
}
#endif