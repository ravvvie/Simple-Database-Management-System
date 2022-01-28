#include "Objects.h"

Main_Menu::Main_Menu(SDL_Renderer* rend)
{
	font_menu = TTF_OpenFont("times.ttf", 42);
	
	if (font_menu == nullptr)
		throw - 13;
	color_text = { 255, 255, 255, 0 };
	name_texture = TextureManager::TextureRender_Text(rend, L"ИНФОРМАЦИОННО-СПРАВОЧНАЯ СИСТЕМА", font_menu, color_text);
	SDL_QueryTexture(name_texture, NULL, NULL, &name_rect.w, &name_rect.h);
	Set_Centre_Rect(&name_rect, 1280);
	name_rect.y = 51;

	TTF_CloseFont(font_menu);

	font_menu = TTF_OpenFont("times.ttf", 30);
	if (font_menu == nullptr)
		throw - 14;


	Show_list_texture = TextureManager::TextureRender_Text(rend, L"Список предприятий", font_menu, color_text);
	Form_list_button_texture = TextureManager::TextureRender_Text(rend, L"Новое предприятие/студент", font_menu, color_text);
	Direct_fac_show_texture = TextureManager::TextureRender_Text(rend, L"Информация предприятий по направлениям", font_menu, color_text);
	contract_quant_texture = TextureManager::TextureRender_Text(rend, L"Количество договоров", font_menu, color_text);
	stud_dir_for_curr_fac_texture = TextureManager::TextureRender_Text(rend, L"Корреляция напревлений студентов и предприятий", font_menu, color_text);
	exit_button_texture = TextureManager::TextureRender_Text(rend, L"Выход", font_menu, color_text);
	SDL_QueryTexture(Show_list_texture, NULL, NULL, &Show_list_rect.w, &Show_list_rect.h);
	SDL_QueryTexture(Form_list_button_texture, NULL, NULL, &Form_list_button_rect.w, &Form_list_button_rect.h);
	SDL_QueryTexture(Direct_fac_show_texture, NULL, NULL, &Direct_fac_show_rect.w, &Direct_fac_show_rect.h);
	SDL_QueryTexture(contract_quant_texture, NULL, NULL, &contract_quant_rect.w, &contract_quant_rect.h);
	SDL_QueryTexture(stud_dir_for_curr_fac_texture, NULL, NULL, &stud_dir_for_curr_fac_rect.w, &stud_dir_for_curr_fac_rect.h);
	SDL_QueryTexture(exit_button_texture, NULL, NULL, &exit_button_rect.w, &exit_button_rect.h);

	Set_Centre_Rect(&Show_list_rect, 1280);
	Show_list_rect.y = 251;

	Set_Centre_Rect(&Form_list_button_rect, 1280);
	Form_list_button_rect.y = 301;

	Set_Centre_Rect(&Direct_fac_show_rect, 1280);
	Direct_fac_show_rect.y = 351;

	Set_Centre_Rect(&contract_quant_rect, 1280);
	contract_quant_rect.y = 401;

	Set_Centre_Rect(&stud_dir_for_curr_fac_rect, 1280);
	stud_dir_for_curr_fac_rect.y = 451;

	Set_Centre_Rect(&exit_button_rect, 1280);
	exit_button_rect.y = 501;

}



void Main_Menu::Set_Centre_Rect(SDL_Rect* current, int cur_res_x)
{
	current->x = (cur_res_x / 2) - (current->w / 2);
}

void Main_Menu::change_text_color(SDL_Renderer* rend, int color, int what)
{
	switch (color)
	{
	case(1):
	{
		color_text = { 255, 255, 255, 0 };
		break;
	}
	case(2):
	{
		color_text = { 0, 0, 0, 0 };
		break;
	}
	}

	switch (what)
	{
		case(1):
		{
			SDL_DestroyTexture(Show_list_texture);
			Show_list_texture = TextureManager::TextureRender_Text(rend, L"Список предприятий", font_menu, color_text);
			break;
		}
		case(2):
		{
			SDL_DestroyTexture(Form_list_button_texture);
			Form_list_button_texture = TextureManager::TextureRender_Text(rend, L"Новое предприятие/студент", font_menu, color_text);
			break;
		}
		case(3):
		{
			SDL_DestroyTexture(Direct_fac_show_texture);
			Direct_fac_show_texture = TextureManager::TextureRender_Text(rend, L"Информация предприятий по направлениям", font_menu, color_text);
			break;
		}
		case(4):
		{
			SDL_DestroyTexture(contract_quant_texture);
			contract_quant_texture = TextureManager::TextureRender_Text(rend, L"Количество договоров", font_menu, color_text);
			break;
		}
		case(5):
		{
			SDL_DestroyTexture(stud_dir_for_curr_fac_texture);
			stud_dir_for_curr_fac_texture = TextureManager::TextureRender_Text(rend, L"Корреляция напревлений студентов и предприятий", font_menu, color_text);
			break;
		}
		
	}
	color_text = { 255, 255, 255, 0 };
}

bool Main_Menu::mouse_detection(int what, int mouse_coord_x, int mouse_coord_y)
{
	switch (what)
	{
		case(1):
		{
			if ((Show_list_rect.x <= mouse_coord_x) && (Show_list_rect.x + Show_list_rect.w >= mouse_coord_x) && (Show_list_rect.y <= mouse_coord_y) && (Show_list_rect.y + Show_list_rect.h >= mouse_coord_y))
				return true;
			break;
		}
		case(2):
		{
			if ((Form_list_button_rect.x <= mouse_coord_x) && (Form_list_button_rect.x + Form_list_button_rect.w >= mouse_coord_x) && (Form_list_button_rect.y <= mouse_coord_y) && (Form_list_button_rect.y + Form_list_button_rect.h >= mouse_coord_y))
				return true;
			break;
		}
		case(3):
		{
			if ((Direct_fac_show_rect.x <= mouse_coord_x) && (Direct_fac_show_rect.x + Direct_fac_show_rect.w >= mouse_coord_x) && (Direct_fac_show_rect.y <= mouse_coord_y) && (Direct_fac_show_rect.y + Direct_fac_show_rect.h >= mouse_coord_y))
				return true;
			break;
		}
		case(4):
		{
			if ((contract_quant_rect.x <= mouse_coord_x) && (contract_quant_rect.x + contract_quant_rect.w >= mouse_coord_x) && (contract_quant_rect.y <= mouse_coord_y) && (contract_quant_rect.y + contract_quant_rect.h >= mouse_coord_y))
				return true;
			break;
		}
		case(5):
		{
			if ((stud_dir_for_curr_fac_rect.x <= mouse_coord_x) && (stud_dir_for_curr_fac_rect.x + stud_dir_for_curr_fac_rect.w >= mouse_coord_x) && (stud_dir_for_curr_fac_rect.y <= mouse_coord_y) && (stud_dir_for_curr_fac_rect.y + stud_dir_for_curr_fac_rect.h >= mouse_coord_y))
				return true;
			break;
		}
	}
	return false;
}

int Main_Menu::Main_Menu_Render(SDL_Renderer*& render)
{
    if (SDL_RenderCopy(render, Get_name_texture(), NULL, Get_name_rect()) < 0)
    {
        return -102;
    }

    if (SDL_RenderCopy(render, Get_Show_list_texture(), NULL, Get_Show_list_rect()) < 0)
    {
        return -103;
    }

    if (SDL_RenderCopy(render, Get_Form_list_button_texture(), NULL, Get_Form_list_button_rect()) < 0)
    {
        return -104;
    }

    if (SDL_RenderCopy(render, Get_contract_quant_texture(), NULL, Get_contract_quant_rect()) < 0)
    { 
        return -105;
    }

    if (SDL_RenderCopy(render, Get_Direct_fac_show_texture(), NULL, Get_Direct_fac_show_rect()) < 0)
    {
        return -106;
    }

    if (SDL_RenderCopy(render,Get_stud_dir_for_curr_fac_texture(), NULL, Get_stud_dir_for_curr_fac_rect()) < 0)
    {
        return -107;
    }

    return 0;
}

Main_Menu::~Main_Menu()
{
	if (name_texture != nullptr)
	{
		SDL_DestroyTexture(name_texture);
		name_texture = nullptr;
	}
	/*if (start_button_texture != nullptr)
	{
		SDL_DestroyTexture(start_button_texture);
		start_button_texture = nullptr;
	}
	*/
	SDL_DestroyTexture(exit_button_texture);
	TTF_CloseFont(font_menu);
}

void Main_Menu::tables_for_input(int& events, SDL_Renderer*& rend, int& menu_events)
{
	int iter{};
	if (buffer1 != nullptr)
	{
		SDL_DestroyTexture(buffer1);
		buffer1 = nullptr;
	}

	if (buffer2 != nullptr)
	{
		SDL_DestroyTexture(buffer2);
		buffer2 = nullptr;
	}

	if (buffer3 != nullptr)
	{
		SDL_DestroyTexture(buffer3);
		buffer3 = nullptr;
	}


	if (buffer4 != nullptr)
	{
		SDL_DestroyTexture(buffer4);
		buffer4 = nullptr;
	}


	switch (menu_events)
	{
	case(2):
	{
		switch (events)
		{
		case(0):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Данные в какой категории будем вводить?", font_menu, color_text);
			buffer2 = TextureManager::TextureRender_Text(rend, L"1. Предприятие", font_menu, color_text);
			buffer3 = TextureManager::TextureRender_Text(rend, L"2. Студент", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			SDL_QueryTexture(buffer2, NULL, NULL, &buff_rect[1].w, &buff_rect[1].h);
			SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
			for (iter; iter < 3; iter++)
				Set_Centre_Rect(&buff_rect[iter], 1280);
			buff_rect[0].y = 300;
			buff_rect[1].y = 420;
			buff_rect[2].y = 420;
			buff_rect[1].x -= buff_rect[1].x / 2;
			buff_rect[2].x += buff_rect[2].x / 2;
			break;
		}
		case(1):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите код направления предприятия", font_menu, color_text);

			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 20);
			if (font_menu == nullptr)
				throw - 14;

			buffer2 = TextureManager::TextureRender_Text(rend, L"(возможные коды предложены в пункте главного меню \"Корреляция напревлений студентов и предприятий\")", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			SDL_QueryTexture(buffer2, NULL, NULL, &buff_rect[1].w, &buff_rect[1].h);

			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 30);
			if (font_menu == nullptr)
				throw - 14;

			buff_rect[0].y = 200;
			buff_rect[1].y = 250;
			for (iter; iter < 2; iter++)
				Set_Centre_Rect(&buff_rect[iter], 1280);
			break;
		}
		case(2):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите название предприятия, которое предпочел студент", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 250;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		case(3):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите название предприятия", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 250;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		case(4):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите группу студента", font_menu, color_text);

			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 20);
			if (font_menu == nullptr)
				throw - 14;

			buffer2 = TextureManager::TextureRender_Text(rend, L"(возможные группы предложены в пункте главного меню \"Корреляция напревлений студентов и предприятий\")", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			SDL_QueryTexture(buffer2, NULL, NULL, &buff_rect[1].w, &buff_rect[1].h);

			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 30);
			if (font_menu == nullptr)
				throw - 14;

			buff_rect[0].y = 200;
			buff_rect[1].y = 250;
			for (iter; iter < 2; iter++)
				Set_Centre_Rect(&buff_rect[iter], 1280);
			break;
		}
		case(5):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите контактную информацию представителя", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 250;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		case(6):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите контактную информацию студента", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 250;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		case(7):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите фамилию человека выбранной категории", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 250;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		case(8):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите имя человека выбранной категории", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 250;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		case(9):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Введите отчество человека выбранной категории", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 250;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		case(10):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Вы успешно заполнили информацию выбранной вами категории", font_menu, color_text);

			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 20);
			if (font_menu == nullptr)
				throw - 14;

			buffer2 = TextureManager::TextureRender_Text(rend, L"(Нажмите \"Escape\", чтобы продолжить...)", font_menu, color_text);
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			SDL_QueryTexture(buffer2, NULL, NULL, &buff_rect[1].w, &buff_rect[1].h);

			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 30);
			if (font_menu == nullptr)
				throw - 14;

			buff_rect[0].y = 200;
			buff_rect[1].y = 250;
			for (iter; iter < 2; iter++)
				Set_Centre_Rect(&buff_rect[iter], 1280);
			break;
		}
		}
		break;
	}
	case(3):
	{
		switch (events)
		{
		case(0):
		{
			buffer1 = TextureManager::TextureRender_Text(rend, L"Выберите код направления, по которому вы хотите посмотреть список предприятий", font_menu, color_text);
			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 20);
			if (font_menu == nullptr)
				throw - 14;
			buffer2 = TextureManager::TextureRender_Text(rend, L"1. Администрирование систем и разработка прикладного ПО", font_menu, color_text);
			buffer3 = TextureManager::TextureRender_Text(rend, L"2. Разработка встраиваемого и программного обеспечения", font_menu, color_text);
			buffer4 = TextureManager::TextureRender_Text(rend, L"3. Разработка встраиваемого и программного обеспечения", font_menu, color_text);
			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 30);
			if (font_menu == nullptr)
				throw - 14;
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			SDL_QueryTexture(buffer2, NULL, NULL, &buff_rect[1].w, &buff_rect[1].h);
			SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
			SDL_QueryTexture(buffer4, NULL, NULL, &buff_rect[3].w, &buff_rect[3].h);
			for (iter; iter < 4; iter++)
				Set_Centre_Rect(&buff_rect[iter], 1280);
			buff_rect[0].y = 200;
			buff_rect[1].y = 320;
			buff_rect[2].y = 420;
			buff_rect[3].y = 520;
			break;
		}
		case(1):
		{
			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 40);
			if (font_menu == nullptr)
				throw - 14;
			buffer1 = TextureManager::TextureRender_Text(rend, L"Организации выбранного вами направления:", font_menu, color_text);
			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 30);
			if (font_menu == nullptr)
				throw - 14;
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			buff_rect[0].y = 50;
			Set_Centre_Rect(&buff_rect[0], 1280);
			break;
		}
		}
		break;
	}
	case(5):
	{
		if (events == 0)
		{
			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 25);
			if (font_menu == nullptr)
				throw - 14;
			buffer1 = TextureManager::TextureRender_Text(rend, L"1. Администрирование систем и разработка прикладного ПО - студенты ПИН, ПРиТ", font_menu, color_text);
			buffer2 = TextureManager::TextureRender_Text(rend, L"2. Администрирование систем и разработка прикладного ПО - студенты ПИН, ИВТ", font_menu, color_text);
			buffer3 = TextureManager::TextureRender_Text(rend, L"3. Разработка встраиваемого и программного обеспечения, техническая защита информации - студенты ИБ, ИВТ", font_menu, color_text);
			TTF_CloseFont(font_menu);
			font_menu = TTF_OpenFont("times.ttf", 30);
			if (font_menu == nullptr)
				throw - 14;
			SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
			SDL_QueryTexture(buffer2, NULL, NULL, &buff_rect[1].w, &buff_rect[1].h);
			SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
			for (iter; iter < 3; iter++)
				Set_Centre_Rect(&buff_rect[iter], 1280);
			buff_rect[0].y = 220;
			buff_rect[1].y = 320;
			buff_rect[2].y = 420;
			break;
		}
		break;
	}
	}
}


int Main_Menu::Render_events(int event_ID, int event_state, SDL_Renderer*& rend)
{
	switch (event_ID)
	{
		case(2):
		{
			switch (event_state)
			{
				case(0):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -250;
					}

					if (SDL_RenderCopy(rend, Get_buffer2(), NULL, Get_buff_rect(1)) < 0)
					{
						return -251;
					}

					if (SDL_RenderCopy(rend, Get_buffer3(), NULL, Get_buff_rect(2)) < 0)
					{
						return -252;
					}
					break;
				}
				case(1):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -254;
					}

					if (SDL_RenderCopy(rend, Get_buffer2(), NULL, Get_buff_rect(1)) < 0)
					{
						return -255;
					}
					break;
				}
				case(2):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -256;
					}

					break;
				}
				case(3):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -257;
					}
					break;
				}
				case(4):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -258;
					}

					if (SDL_RenderCopy(rend, Get_buffer2(), NULL, Get_buff_rect(1)) < 0)
					{
						return -259;
					}
					break;
				}
				case(5):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -260;
					}
					break;
				}
				case(6):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -260;
					}
					break;
				}
				case(7):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -261;
					}
					break;
				}
				case(8):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -262;
					}
					break;
				}
				case(9):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -263;
					}
					break;
				}
				case(10):
				{
					if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
					{
						return -264;
					}

					if (SDL_RenderCopy(rend, Get_buffer2(), NULL, Get_buff_rect(1)) < 0)
					{
						return -265;
					}
					break;
				}
			}
			break;
		}
		case(3):
		{
			switch (event_state)
			{
			case(0):
			{
				if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
				{
					return -266;
				}

				if (SDL_RenderCopy(rend, Get_buffer2(), NULL, Get_buff_rect(1)) < 0)
				{
					return -267;
				}

				if (SDL_RenderCopy(rend, Get_buffer3(), NULL, Get_buff_rect(2)) < 0)
				{
					return -268;
				}

				if (SDL_RenderCopy(rend, Get_buffer4(), NULL, Get_buff_rect(3)) < 0)
				{
					return -269;
				}
				break;
			}
			case(1):
			{
				if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
				{
					return -270;
				}
				break;
			}
			}
			break;
		}
		case(5):
		{
			if (event_state == 0)
			{
				if (SDL_RenderCopy(rend, Get_buffer1(), NULL, Get_buff_rect(0)) < 0)
				{
					return -266;
				}

				if (SDL_RenderCopy(rend, Get_buffer2(), NULL, Get_buff_rect(1)) < 0)
				{
					return -267;
				}

				if (SDL_RenderCopy(rend, Get_buffer3(), NULL, Get_buff_rect(2)) < 0)
				{
					return -268;
				}
			}
			
		}
	}
	return 0;
}

void Main_Menu::Message_error(int type, SDL_Renderer*& rend, int quant_chars)
{
	switch (type)
	{
	case(1):
	{
		if (buffer3 != nullptr)
		{
			SDL_DestroyTexture(buffer3);
			buffer3 = nullptr;
		}
		buffer3 = TextureManager::TextureRender_Text(rend, L"Неверно набранное направление", font_menu, color_text);
		
		SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
		buff_rect[2].y = 640;
		Set_Centre_Rect(&buff_rect[2], 1280);

		break;
	}
	case(2):
	{
		if (buffer3 != nullptr)
		{
			SDL_DestroyTexture(buffer3);
			buffer3 = nullptr;
		}
		buffer3 = TextureManager::TextureRender_Text(rend, L"Ввод пустой строки или \"пробелов\" не допускается", font_menu, color_text);

		SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
		buff_rect[2].y = 640;
		Set_Centre_Rect(&buff_rect[2], 1280);

		break;
	}
	case(3):
	{
		if (buffer3 != nullptr)
		{
			SDL_DestroyTexture(buffer3);
			buffer3 = nullptr;
		}

		buffer3 = TextureManager::TextureRender_Text(rend, L"Недопутимое значение. Введное направление (и\\или предприятие) не верны", font_menu, color_text);

		SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
		buff_rect[2].y = 640;
		Set_Centre_Rect(&buff_rect[2], 1280);

		break;
	}
	case(4):
	{
		if (buffer5 != nullptr)
		{
			SDL_DestroyTexture(buffer5);
			buffer5 = nullptr;
		}

		buffer5 = TextureManager::TextureRender_Text(rend, L"По данному коду направления нет ни одного предприятия", font_menu, color_text);

		SDL_QueryTexture(buffer5, NULL, NULL, &buff_rect[4].w, &buff_rect[4].h);
		buff_rect[4].y = 640;
		Set_Centre_Rect(&buff_rect[4], 1280);

		break;
	}
	case(5):
	{
		if (buffer3 != nullptr)
		{
			SDL_DestroyTexture(buffer3);
			buffer3 = nullptr;
		}
		std::wstring buff = std::to_wstring(quant_chars);
		buffer3 = TextureManager::TextureRender_Text(rend, L"Минимальное кол-во символов для данной строки - " + buff, font_menu, color_text);

		SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
		buff_rect[2].y = 640;
		Set_Centre_Rect(&buff_rect[2], 1280);
	}
	case(6):
	{
		if (buffer3 != nullptr)
		{
			SDL_DestroyTexture(buffer3);
			buffer3 = nullptr;
		}

		buffer3 = TextureManager::TextureRender_Text(rend, L"Название данного предприятия уже есть в списке", font_menu, color_text);

		SDL_QueryTexture(buffer3, NULL, NULL, &buff_rect[2].w, &buff_rect[2].h);
		buff_rect[2].y = 640;
		Set_Centre_Rect(&buff_rect[2], 1280);
	}
	}
}

void Main_Menu:: Stud_quant_show(int& stud_quant, SDL_Renderer* rend)
{
	if (buffer1 != nullptr)
	{
		SDL_DestroyTexture(buffer1);
		buffer1 = nullptr;
	}
	std::wstring buff = std::to_wstring(stud_quant);
	buffer1 = TextureManager::TextureRender_Text(rend, L"Количество студентов, проходящих практику - " + buff, font_menu, color_text);
	SDL_QueryTexture(buffer1, NULL, NULL, &buff_rect[0].w, &buff_rect[0].h);
	buff_rect[0].y = 260;
	Set_Centre_Rect(&buff_rect[0], 1280);
}