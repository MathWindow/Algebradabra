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
	// title & extra title

	// test

	c_size_t title_index_just_message
		= put_index_counter<size_t>(0);

	c_size_t extra_title_index_it_is_a_test
		= put_index_counter<size_t>(0);

	// window's class name

	c_size_t title_index_cannot_register_class_name
		= put_index_counter<size_t>(continue_counting);

	c_size_t extra_title_index_cannot_register_unknown_class_name
		= put_index_counter<size_t>(continue_counting);

	// main function

	c_size_t title_index_main_function_was_called
		= put_index_counter<size_t>(continue_counting);

	c_size_t extra_title_index_main_function_was_called
		= put_index_counter<size_t>(continue_counting);

	// block's hierarchy

	c_size_t title_index_block_hierarchy_has_not_been_pointed
		= put_index_counter<size_t>(continue_counting);

	c_size_t extra_title_index_block_hierarchy_has_not_been_pointed
		= put_index_counter<size_t>(continue_counting);

	// handle

	c_size_t title_index_handle_was_created
		= put_index_counter<size_t>(continue_counting);
	c_size_t title_index_couldnt_create_handle
		= put_index_counter<size_t>(continue_counting);
	c_size_t title_index_instance_was_pointed
		= put_index_counter<size_t>(continue_counting);
	c_size_t title_index_handle_has_not_been_pointed
		= put_index_counter<size_t>(continue_counting);

	c_size_t extra_title_index_handle_was_created
		= put_index_counter<size_t>(continue_counting);
	c_size_t extra_title_index_could_not_create_handle
		= put_index_counter<size_t>(continue_counting);
	c_size_t extra_title_index_instance_was_pointed
		= put_index_counter<size_t>(continue_counting);
	c_size_t extra_title_index_handle_has_not_been_pointed
		= put_index_counter<size_t>(continue_counting);

	// operator "new"

	c_size_t title_index_operator_new_was_called
		= put_index_counter<size_t>(continue_counting);

	c_size_t extra_title_index_operator_new_was_called
		= put_index_counter<size_t>(continue_counting);

	// command

	c_size_t title_index_command_has_not_been_pointed
		= put_index_counter<size_t>(continue_counting);

	c_size_t extra_title_index_command_has_not_been_pointed
		= put_index_counter<size_t>(continue_counting);

	// splitting by zero

	c_size_t title_index_split_by_zero
		= put_index_counter<size_t>(continue_counting);

	c_size_t extra_title_index_split_by_zero
		= put_index_counter<size_t>(continue_counting);


	// event's type

	using event_type_index = u_char_;
	using c_event_type_index = const event_type_index;

	c_event_type_index event_type_message
		= put_index_counter<event_type_index>(0);
	c_event_type_index event_type_question
		= put_index_counter<event_type_index>(continue_counting);
	c_event_type_index event_type_warning
		= put_index_counter<event_type_index>(continue_counting);
	c_event_type_index event_type_error
		= put_index_counter<event_type_index>(continue_counting);

	// handle type

	using handle_type_index = u_char_;
	using c_handle_type_index = const handle_type_index;

	c_handle_type_index handle_type_none
		= put_index_counter<handle_type_index>(0);
	c_handle_type_index handle_type_unknown
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_simple
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_window
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_menu
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_icon
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_bitmap
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_instance
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_brush
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_context
		= put_index_counter<handle_type_index>(continue_counting);
	c_handle_type_index handle_type_font
		= put_index_counter<handle_type_index>(continue_counting);

	handle_type_index translate_handle_type_to_index(
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
		else {
			return handle_type_unknown;
		}
	}

	// class

	class event_information {
	public:
		event_type_index event_type = event_type_message;

		size_t title_index = 0;
		size_t extra_title_index = 0;

		std::vector<coding::block_information> block_hierarchy{};

		void* handle_value = nullptr;
		handle_type_index handle_type = handle_type_none;
		std::wstring window_class_name = L"";
		
		size_t index_about_other_event_plus_one = 0;

		SYSTEMTIME time_system{};
		SYSTEMTIME time_local{};

		translate::string show_type() {
			if (event_type == event_type_message) {
				return translate::set_string(
					L"Message",
					L"Сообщение"
				);
			}
			else if (event_type == event_type_question) {
				return translate::set_string(
					L"Question",
					L"Вопрос"
				);
			}
			else if (event_type == event_type_warning) {
				return translate::set_string(
					L"Warning",
					L"Предупреждение"
				);
			}
			else if (event_type == event_type_error) {
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

		translate::string show_title() {
			if (title_index == title_index_just_message) {
				return translate::set_string(
					L"Just a message",
					L"Просто сообщение"
				);
			}
			else if (title_index == title_index_cannot_register_class_name) {
				return translate::set_string(
					L"Couldn't create class' name",
					L"Не удалось создать имя класса"
				);
			}
			else if (title_index == title_index_main_function_was_called) {
				return translate::set_string(
					L"Main function was called",
					L"Главная функция была вызвана"
				);
			}
			else if (title_index == title_index_block_hierarchy_has_not_been_pointed) {
				return translate::set_string(
					L"Block's hierarchy hasn't been pointed",
					L"Иерархия блока не указана"
				);
			}
			else if (title_index == title_index_handle_was_created) {
				return translate::set_string(
					L"Handle was created",
					L"Дескриптор был создан"
				);
			}
			else if (title_index == title_index_couldnt_create_handle) {
				return translate::set_string(
					L"Couldn't create handle",
					L"Не удалось создать дескриптор"
				);
			}
			else if (title_index == title_index_instance_was_pointed) {
				return translate::set_string(
					L"Instance was pointed",
					L"Наследование было указано"
				);
			}
			else if (title_index == title_index_operator_new_was_called) {
				return translate::set_string(
					L"Operator \"new\" was called",
					L"Оператор \"new\" был вызван"
				);
			}
			else if (title_index == title_index_handle_has_not_been_pointed) {
				return translate::set_string(
					L"Handle hasn't been pointed",
					L"Дескриптор не был указан"
				);
			}
			else if (title_index == title_index_command_has_not_been_pointed) {
				return translate::set_string(
					L"Command has not been pointed",
					L"Команда не была указана"
				);
			}
			else if (title_index == title_index_split_by_zero) {
				return translate::set_string(
					L"Program has tried to split number by zero",
					L"Программа попыталась делить число на ноль"
				);
			}

			return translate::set_string(
				L"Where is title?",
				L"Где заголовок?"
			);
		}

		translate::string show_extra_title() {
			if (extra_title_index == extra_title_index_it_is_a_test) {
				return translate::set_string(
					L"This is a test",
					L"Это является тестом"
				);
			}
			else if (extra_title_index == extra_title_index_cannot_register_unknown_class_name) {
				return translate::set_string(
					L"Couldn't create class' name for unknown window",
					L"Не удалось создать имя класса для неизвестного окна"
				);
			}
			else if (extra_title_index == extra_title_index_main_function_was_called) {
				return translate::set_string(
					L"Main function was called by program",
					L"Главная функция вызвана программами"
				);
			}
			else if (extra_title_index == extra_title_index_block_hierarchy_has_not_been_pointed) {
				return translate::set_string(
					L"Block's hierarchy hasn't been pointed by developer",
					L"Иерархия блока не указана разработчиком"
				);
			}
			else if (extra_title_index == extra_title_index_handle_was_created) {
				return translate::set_string(
					L"Handle was created",
					L"Дескриптор был создан"
				);
			}
			else if (extra_title_index == extra_title_index_could_not_create_handle) {
				return translate::set_string(
					L"Couldn't create handle",
					L"Не удалось создать дескриптор"
				);
			}
			else if (extra_title_index == extra_title_index_instance_was_pointed) {
				return translate::set_string(
					L"Instance was pointed by handle",
					L"Наследование было указано дескриптором"
				);
			}
			else if (extra_title_index == extra_title_index_operator_new_was_called) {
				return translate::set_string(
					L"Operator \"new\" was called. It can make problem, especially if operator \"delete\" was forgotten to write.",
					L"Оператор \"new\" был вызван. Это может создавать проблему, особенно если оператор \"delete\" забыт в написании."
				);
			}
			else if (extra_title_index == extra_title_index_handle_has_not_been_pointed) {
				return translate::set_string(
					L"Handle hasn't been pointed",
					L"Дескриптор не был указан"
				);
			}
			else if (extra_title_index == extra_title_index_command_has_not_been_pointed) {
				return translate::set_string(
					L"Command has not been pointed",
					L"Команда не была указана"
				);
			}
			else if (extra_title_index == extra_title_index_split_by_zero) {
				return translate::set_string(
					L"Program has tried to split number by zero. Splitting by zero is not possible.",
					L"Программа попыталась делить число на ноль. Деление на ноль не представляется возможным."
				);
			}

			return translate::set_string(
				L"Where is extra title?",
				L"Где расширенный заголовок?"
			);
		}

		translate::string show_handle_type( ) {
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

		std::wstring show_index_about_other_event() {
			return index_about_other_event_plus_one != 0 
				? std::to_wstring(index_about_other_event_plus_one - 1) 
				: L"";
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
				show_title().show(),
				show_extra_title().show(),
				show_handle_value(),
				show_handle_type().show(),
				window_class_name,
				show_index_about_other_event(),
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
		event_type_index event_type,
		size_t title_index,
		size_t extra_title_index,
		std::vector<coding::block_information> block_hierarchy,
		void* handle,
		handle_type_index handle_type,
		std::wstring window_class_name
	) {
		size_t index_of_writing_event = list_of_event.size();

		list_of_event.push_back({});

		GetSystemTime(&list_of_event.back().time_system);
		GetLocalTime(&list_of_event.back().time_local);

		list_of_event.back().event_type = event_type;
		list_of_event.back().title_index = title_index;
		list_of_event.back().extra_title_index = extra_title_index;
		list_of_event.back().block_hierarchy = block_hierarchy;
		list_of_event.back().handle_value = handle;
		list_of_event.back().handle_type = handle_type;
		list_of_event.back().window_class_name = window_class_name;
	}

	void write_event_about_handle(
		std::vector<coding::block_information> block_hierarchy,
		void* handle,
		handle_type_index handle_type,
		std::wstring window_class_name
	) {
		if (handle == nullptr) {
			write_event(
				event_type_error,
				title_index_couldnt_create_handle,
				extra_title_index_could_not_create_handle,
				block_hierarchy,
				handle,
				handle_type,
				window_class_name
			);
		}
		else if(handle_type == handle_type_instance) {
			write_event(
				event_type_message,
				title_index_instance_was_pointed,
				extra_title_index_instance_was_pointed,
				block_hierarchy,
				handle,
				handle_type,
				window_class_name
			);
		}
		else {
			write_event(
				event_type_message,
				title_index_handle_was_created,
				extra_title_index_handle_was_created,
				block_hierarchy,
				handle,
				handle_type,
				window_class_name
			);
		}
	}

	HWND __stdcall create_window_ex_w(
		DWORD extra_style,
		LPCWSTR class_name,
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
			class_name,
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

		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			class_name
		);

		return result;
	}

	HMENU _stdcall create_menu(macro_add_block_argument) {
		HMENU result = CreateMenu();

		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);

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

		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);

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

		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);

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

		write_event_about_handle(
			place_argument,
			result,
			translate_handle_type_to_index(typeid(result).name()),
			L""
		);

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
			write_event( 
				event_type_error,
				title_index_handle_has_not_been_pointed,
				extra_title_index_handle_has_not_been_pointed,
				place_argument,
				nullptr,
				translate_handle_type_to_index(typeid(h_menu).name()),
				L""
			);
		}
		else {
			AppendMenuW(h_menu, flags, command, title);
		}

		if (command == NULL && (flags & MF_SEPARATOR) != MF_SEPARATOR) {
			write_event( 
				event_type_warning,
				title_index_command_has_not_been_pointed,
				extra_title_index_command_has_not_been_pointed,
				place_argument,
				h_menu,
				translate_handle_type_to_index(typeid(h_menu).name()),
				L""
			);
		}
	}
}

#define macro_operator_new_array(variable_name, type, size) type * variable_name = new type[size]{}; \
	debug::write_event( \
		debug::event_type_warning, \
		debug::title_index_operator_new_was_called, \
		debug::extra_title_index_operator_new_was_called, \
		place, \
		nullptr, \
		debug::handle_type_none, \
		L"" \
	)

#endif
