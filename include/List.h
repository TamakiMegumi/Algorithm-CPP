#pragma once
#include<cstddef>
namespace Algorithm {
	template<typename T>
	class List {
	public:
		struct Node {
			Node* pre;
			Node* next;
			T val;
			Node(const T& val, Node* pre, Node* next) :val(val), pre(pre), next(next) {}
			Node(const T& val) :Node(val, nullptr, nullptr) {}
			Node() :Node(T{}) {}
		};
	private:
		Node dummy{};
		size_t length = 0;
	public:
		List();
		List(const List& o);
		~List();
		const List& operator=(const List& o);

		size_t size() const;
		bool empty() const;

		void push_back(const T& val);
		void pop_back();
		void push_front(const T& val);
		void pop_front();

		T& front();
		const T& front()const;
		T& back();
		const T& back()const;

		void insert(Node* ptr, const T& val);
		void erase(Node* ptr);
		void clear();

		Node* data();
		const Node* data()const;
	};

	template<typename T>
	List::List() {

	}

	template<typename T>
	List::List(const List& o) {

	}

	template<typename T>
	List::~List() {

	}

	template<typename T>
	const List& List::operator=(const List& o) {

	}

	template<typename T>
	size_t List::size() const {

	}

	template<typename T>
	bool List::empty() const {

	}

	template<typename T>
	void List::push_back(const T& val) {

	}

	template<typename T>
	void List::pop_back() {

	}

	template<typename T>
	void List::push_front(const T& val) {

	}

	template<typename T>
	void List::pop_front() {

	}

	template<typename T>
	T& List::front() {

	}

	template<typename T>
	const T& List::front()const {

	}

	template<typename T>
	T& List::back() {

	}

	template<typename T>
	const T& List::back()const {

	}

	template<typename T>
	void insert(Node* ptr, const T& val) {

	}

	template<typename T>
	void erase(Node* ptr) {

	}

	template<typename T>
	void clear() {

	}

	template<typename T>
	Node* data() {

	}

	template<typename T>
	const Node* data()const {

	}
}