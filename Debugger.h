#pragma once
#include <vector>
#include <Windows.h>
#include <minwinbase.h>
#include <sysinfoapi.h>
#include <string>
#include <fileapi.h>
#include <typeinfo>
#include <basetsd.h>
#include "StringWork.h"
#include "ShortTypes.h"
#include "Counter.h"
#include "Translate.h"
#include "CodeWork.h"

#ifndef macro_header_debugger
#define macro_header_debugger

namespace debug {
#if turn_debugger_on
	// event's type

	using event_type = u_char_;
	using c_event_type = const event_type;

	c_event_type event_type_message
		= put_index_counter<event_type>(0);
	c_event_type event_type_question
		= put_index_counter<event_type>(continue_counting);
	c_event_type event_type_warning
		= put_index_counter<event_type>(continue_counting);
	c_event_type event_type_error
		= put_index_counter<event_type>(continue_counting);

	// title & extra title

	using title_index = u_char_;
	using c_title_index = const title_index;

	class title {
	public:
		title_index index = 0;
		event_type event_type_ = 0;
	};

	title set_title(
		event_type event_type
	) {
		title result{};

		static title_index index_ = 0;

		result.index = index_;
		result.event_type_ = event_type;

		index_++;

		return result;
	}

	// window's class name

	title title_cannot_register_class_name
		= set_title(event_type_error);

	// main function

	title title_main_function_was_called
		= set_title(event_type_message);

	// block's hierarchy

	title title_block_hierarchy_has_not_been_pointed
		= set_title(event_type_error);

	// handle

	title title_handle_was_created
		= set_title(event_type_message);
	title title_could_not_create_handle
		= set_title(event_type_error);
	title title_instance_was_pointed
		= set_title(event_type_message);
	title title_handle_has_not_been_pointed
		= set_title(event_type_error);

	// operator "new"

	title title_operator_new_was_called
		= set_title(event_type_warning);

	// command

	title title_command_has_not_been_pointed
		= set_title(event_type_error);

	// splitting by zero

	title title_split_by_zero
		= set_title(event_type_error);

	// handle type

	using handle_type = u_char_;
	using c_handle_type = const handle_type;

	c_handle_type handle_type_none
		= put_index_counter<handle_type>(0);
	c_handle_type handle_type_unknown
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_simple
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_window
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_menu
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_icon
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_bitmap
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_instance
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_brush
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_context
		= put_index_counter<handle_type>(continue_counting);
	c_handle_type handle_type_font
		= put_index_counter<handle_type>(continue_counting);

	handle_type translate_handle_type_to_index(
		LPCSTR name 
	) {
		if (name == typeid(HANDLE).name()) {
			return handle_type_simple;
		}
		else if (name == typeid(HWND).name()) {
			return handle_type_window;
		}
		else if (name == typeid(HMENU).name()) {
			return handle_type_menu;
		}
		else if (name == typeid(HICON).name()) {
			return handle_type_icon;
		}
		else if (name == typeid(HBITMAP).name()) {
			return handle_type_bitmap;
		}
		else if (name == typeid(HINSTANCE).name()) {
			return handle_type_instance;
		}
		else if (name == typeid(HBRUSH).name()) {
			return handle_type_brush;
		}
		else if (name == typeid(HDC).name()) {
			return handle_type_context;
		}
		else if (name == typeid(HFONT).name()) {
			return handle_type_font;
		}

		return handle_type_unknown;
	}

	// class "event's information"

	class event_information {
	public:
		std::vector<coding::block_information> block_hierarchy{};

		title title_;

		void* handle_value = nullptr;
		handle_type handle_type = handle_type_none;
		std::wstring window_class_name = L"";

		SYSTEMTIME time_system{};
		SYSTEMTIME time_local{};

		translate::string show_type() {
			if (title_.event_type_ == event_type_message) {
				return translate::set_string(
					L"Message",
					L"Сообщение"
				);
			}
			else if (title_.event_type_ == event_type_question) {
				return translate::set_string(
					L"Question",
					L"Вопрос"
				);
			}
			else if (title_.event_type_ == event_type_warning) {
				return translate::set_string(
					L"Warning",
					L"Предупреждение"
				);
			}
			else if (title_.event_type_ == event_type_error) {
				return translate::set_string(
					L"Error",
					L"Ошибка"
				);
			}

			return translate::set_string(
				L"Where is type?",
				L"Где тип?"
			);
		}

		translate::string show_title(bool is_extra) {
			if (title_.index == title_cannot_register_class_name.index) {
				return translate::set_string(
					L"Couldn't create class' name",
					L" for window",
					L"Не удалось создать имя класса",
					L" для окна",
					is_extra
				);
			}
			else if (title_.index == title_main_function_was_called.index) {
				return translate::set_string(
					L"Main function was called",
					L" by program",
					L"Главная функция была вызвана",
					L" программой",
					is_extra
				);
			}
			else if (title_.index == title_block_hierarchy_has_not_been_pointed.index) {
				return translate::set_string(
					L"Block's hierarchy hasn't been pointed",
					L" by developer",
					L"Иерархия блока не указана",
					L" разработчиком",
					is_extra
				);
			}
			else if (title_.index == title_handle_was_created.index) {
				return translate::set_string(
					L"Handle was created",
					L"Дескриптор был создан"
				);
			}
			else if (title_.index == title_could_not_create_handle.index) {
				return translate::set_string(
					L"Couldn't create handle",
					L"Не удалось создать дескриптор"
				);
			}
			else if (title_.index == title_instance_was_pointed.index) {
				return translate::set_string(
					L"Instance was pointed",
					L" дескриптором",
					L"Наследование было указано",
					L" by handle",
					is_extra
				);
			}
			else if (title_.index == title_operator_new_was_called.index) {
				return translate::set_string(
					L"Operator \"new\" was called",
					L". It can make problem, especially if operator \"delete\" was forgotten to write.",
					L"Оператор \"new\" был вызван",
					L". Это может создавать проблему, особенно если оператор \"delete\" забыт в написании.",
					is_extra
				);
			}
			else if (title_.index == title_handle_has_not_been_pointed.index) {
				return translate::set_string(
					L"Handle hasn't been pointed",
					L"Дескриптор не был указан"
				);
			}
			else if (title_.index == title_command_has_not_been_pointed.index) {
				return translate::set_string(
					L"Command has not been pointed",
					L"Команда не была указана"
				);
			}
			else if (title_.index == title_split_by_zero.index) {
				return translate::set_string(
					L"Program has tried to split number by zero",
					L". Splitting by zero is not possible.",
					L"Программа попыталась делить число на ноль",
					L". Деление на ноль не представляется возможным.",
					is_extra
				);
			}

			if (is_extra) {
				return translate::set_string(
					L"Where is extra title?",
					L"Где расширенный заголовок?"
				);
			}
			else {
				return translate::set_string(
					L"Where is title?",
					L"Где заголовок?"
				);
			}
		}

		translate::string show_handle_type() {
			if (handle_type == handle_type_unknown) {
				return translate::set_string(
					L"Unknown type",
					L"Неизвестный тип"
				);
			}
			else if (handle_type == handle_type_simple) {
				return translate::set_string(
					L"Simple type",
					L"Простой тип"
				);
			}
			else if (handle_type == handle_type_window) {
				return translate::set_string(
					L"Window",
					L"Окно"
				);
			}
			else if (handle_type == handle_type_menu) {
				return translate::set_string(
					L"Menu",
					L"Меню"
				);
			}
			else if (handle_type == handle_type_icon) {
				return translate::set_string(
					L"Icon",
					L"Иконка"
				);
			}
			else if (handle_type == handle_type_bitmap) {
				return translate::set_string(
					L"Bitmap",
					L"Битовая карта"
				);
			}
			else if (handle_type == handle_type_instance) {
				return translate::set_string(
					L"Instance",
					L"Наследие"
				);
			}
			else if (handle_type == handle_type_brush) {
				return translate::set_string(
					L"Brush",
					L"Кисть"
				);
			}
			else if (handle_type == handle_type_context) {
				return translate::set_string(
					L"Context description",
					L"Описание контекста"
				);
			}
			else if (handle_type == handle_type_font) {
				return translate::set_string(
					L"Font",
					L"Шрифт"
				);
			}
			else {
				return translate::set_string(
					L"",
					L""
				);
			}
		}

		std::wstring show_handle_value() {
			if (handle_type != handle_type_none) {
				return std::to_wstring((int)handle_value);
			}
			else {
				return L"";
			}
		}

		std::wstring show_time(bool is_local) {
			SYSTEMTIME time = is_local ? time_local : time_system;

			return auto_adding_zero(time.wHour)
				+ L":" + auto_adding_zero(time.wMinute)
				+ L":" + auto_adding_zero(time.wSecond)
				+ L"; " + auto_adding_zero(time.wDay)
				+ L"." + auto_adding_zero(time.wMonth)
				+ L"." + std::to_wstring(time.wYear);
		}

		std::vector<std::wstring> show_string_array() {
			return {
				show_type().show(),
				show_title(false).show(),
				show_title(true).show(),
				show_handle_value(),
				show_handle_type().show(),
				window_class_name,
				show_time(true),
				show_time(false)
			};
		}
	};

	std::vector<event_information> list_of_event{};

	std::vector<std::vector<std::wstring>> show_2d_string_list_of_event() {
		std::vector<std::vector<std::wstring>> result{};

		for ( 
			size_t index_list = 0;
			index_list < list_of_event.size();
			index_list++
		) {
			result.push_back(list_of_event.at(index_list).show_string_array());
		}

		return result;
	}


	void write_event(
		title title_,
		std::vector<coding::block_information> block_hierarchy,
		void* handle,
		handle_type handle_type,
		std::wstring window_class_name
	) {
		list_of_event.push_back({});

		GetSystemTime(&list_of_event.back().time_system);
		GetLocalTime(&list_of_event.back().time_local);

		list_of_event.back().title_ = title_;
		list_of_event.back().block_hierarchy = block_hierarchy;
		list_of_event.back().handle_value = handle;
		list_of_event.back().handle_type = handle_type;
		list_of_event.back().window_class_name = window_class_name;
	}

	void write_event_about_handle(
		std::vector<coding::block_information> block_hierarchy,
		void* handle,
		handle_type handle_type,
		std::wstring window_class_name
	) {
		if (handle == nullptr) {
			write_event(
				title_handle_has_not_been_pointed,
				block_hierarchy,
				handle,
				handle_type,
				window_class_name
			);
		}
		else if(handle_type == handle_type_instance) {
			write_event(
				title_instance_was_pointed,
				block_hierarchy,
				handle,
				handle_type,
				window_class_name
			);
		}
		else {
			write_event(
				title_handle_was_created,
				block_hierarchy,
				handle,
				handle_type,
				window_class_name
			);
		}
	}
#endif
	HWND __stdcall create_window_ex_w_modification (
		DWORD extra_style,
		std::wstring class_name,
		LPCWSTR title,
		DWORD style,
		int abscissa,
		int ordinate,
		int width,
		int height,
		HWND h_window_parent,
		HMENU command,
		HINSTANCE h_instance,
		LPVOID l_param,
		macro_add_block_argument
	) {
		HWND result = CreateWindowExW( 
			extra_style,
			class_name.c_str(),
			title,
			style,
			abscissa,
			ordinate,
			width,
			height,
			h_window_parent,
			command,
			h_instance,
			l_param
		);
#if turn_debugger_on
		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			class_name
		);
#endif
		return result;
	}

	HMENU _stdcall create_menu(macro_add_block_argument) {
		HMENU result = CreateMenu();
#if turn_debugger_on
		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);
#endif
		return result;
	}

	HANDLE __stdcall create_file_w(
		LPCWSTR file_with_path,
		DWORD desired_access,
		DWORD share_mode,
		LPSECURITY_ATTRIBUTES security_attributes,
		DWORD creation_disposition,
		DWORD flags_and_attributes,
		HANDLE h_template_file,
		macro_add_block_argument
	) {
		HANDLE result = CreateFileW(
			file_with_path,
			desired_access,
			share_mode,
			security_attributes,
			creation_disposition,
			flags_and_attributes,
			h_template_file
		);
#if turn_debugger_on
		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);
#endif
		return result;
	}

	HANDLE __stdcall create_file_a(
		LPCSTR file_with_path,
		DWORD desired_access,
		DWORD share_mode,
		LPSECURITY_ATTRIBUTES security_attributes,
		DWORD creation_disposition,
		DWORD flags_and_attributes,
		HANDLE h_template_file,
		macro_add_block_argument
	) {
		HANDLE result = CreateFileA(
			file_with_path,
			desired_access,
			share_mode,
			security_attributes,
			creation_disposition,
			flags_and_attributes,
			h_template_file
		);
#if turn_debugger_on
		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);
#endif
		return result;
	}

	HICON __stdcall load_icon_w(
		HINSTANCE h_instance,
		LPCWSTR string,
		macro_add_block_argument
	) {
		HICON result = LoadIconW(
			h_instance,
			string
		);
#if turn_debugger_on
		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);
#endif
		return result;
	}

	HBITMAP __stdcall load_bitmap_w(
		HINSTANCE h_instance,
		LPCWSTR string,
		macro_add_block_argument
	) {
		HBITMAP result = LoadBitmapW(
			h_instance,
			string
		);
#if turn_debugger_on
		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);

		if (h_instance != nullptr) {
			write_event_about_handle(
				place_argument,
				h_instance,
				translate_handle_type_to_index(typeid(h_instance).name()),
				L""
			);
		}
#endif
		return result;
	}

	void append_menu_w(
		HMENU h_menu,
		UINT flags,
		UINT_PTR command,
		LPCWSTR title,
		macro_add_block_argument
	) {
		if (h_menu == nullptr) {
#if turn_debugger_on
			write_event(
				title_handle_has_not_been_pointed,
				place_argument,
				nullptr,
				translate_handle_type_to_index(typeid(h_menu).name()),
				L""
			);
#endif
		}
		else {
			AppendMenuW(h_menu, flags, command, title);
		}

		if (command == NULL && (flags & MF_SEPARATOR) != MF_SEPARATOR) {
#if turn_debugger_on
			write_event(
				title_command_has_not_been_pointed,
				place_argument,
				h_menu,
				translate_handle_type_to_index(typeid(h_menu).name()),
				L""
			);
#endif
		}
	}
}

#endif