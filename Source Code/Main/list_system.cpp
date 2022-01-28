#include "Objects.h"

_fac::_fac()
{
	direct_rect.h = 35;
	direct_rect.w = 20;
	direct_rect.x = 160;

	denom_rect.h = 35;
	denom_rect.w = 120;
	denom_rect.x = 300;

	_fac_member_rect.h = 35;
	_fac_member_rect.w = 300;
	_fac_member_rect.x = 500;

	info_rect.h = 35;
	info_rect.w = 200;
	info_rect.x = 865;
}

_stud::_stud()
{
	ID_rect.h = 25;
	ID_rect.w = 15;
	ID_rect.x = 200;

	NSP_rect.h = 25;
	NSP_rect.w = 200;
	NSP_rect.x = 300;

	dir_stud_rect.h = 25;
	dir_stud_rect.w = 75;
	dir_stud_rect.x = 575;

	info_rect.h = 25;
	info_rect.w = 150;
	info_rect.x = 775;
}


d_l_List::d_l_List(SDL_Renderer*& rend)
	: head_fac(nullptr), curr_fac(head_fac), size_fac(0),
	Table_direct_rect {	100, 35, 150, 35},
	Table_denom_rect{ 270, 35, 180, 35 },
	Table_fac_member_rect{ 480, 35, 350, 35 },
	Table_info_rect{ 860, 35, 220, 35 },
	count_fac_by_dir{-1, -1, -1, -1 }
{
	table_font = TTF_OpenFont("times.ttf", 40);
	Table_direct_text = TextureManager::TextureRender_Text(rend, L"Направление", table_font, table_color);
	Table_denom_text = TextureManager::TextureRender_Text(rend, L"Организация", table_font, table_color);
	Table_fac_member_text = TextureManager::TextureRender_Text(rend, L"ФИО представителя", table_font, table_color);
	Table_info_text = TextureManager::TextureRender_Text(rend, L"Контактная информация", table_font, table_color);
}



d_l_List :: ~d_l_List()
{
	if (curr_fac != nullptr)
	{
		curr_fac = nullptr;
		head_fac = nullptr;
	}
}



bool d_l_List::push_back_fac(_fac& data, SDL_Renderer*& rend)
{
	
	switch (size_fac)
	{
	case(0):
	{
		head_fac = new Node_fac(data, rend);
		break;
	}
	case(1):
	{
		head_fac->pPrev_fac = new Node_fac(data, rend);
		head_fac->pPrev_fac->pNext_fac = head_fac;
		head_fac->pPrev_fac->pPrev_fac = head_fac;
		head_fac->pNext_fac = head_fac->pPrev_fac;
		curr_fac = head_fac->pPrev_fac;
		break;
	}
	default:
	{
		curr_fac = head_fac->pPrev_fac;
		head_fac->pPrev_fac = new Node_fac(data, rend);
		curr_fac->pNext_fac = head_fac->pPrev_fac;
		curr_fac->pNext_fac->pPrev_fac = curr_fac;
		curr_fac->pNext_fac->pNext_fac = head_fac;
		curr_fac = curr_fac->pNext_fac;
		break;
	}
	}
	size_fac++;
	if (size_fac == 1)
	{
		curr_fac = head_fac;
		curr_fac->data.direct_rect.y = 100;
	}
	else
		curr_fac->data.direct_rect.y = curr_fac->pPrev_fac->data.direct_rect.y + curr_fac->pPrev_fac->fac_frame + 100;

	curr_fac->data.denom_rect.y = curr_fac->data.direct_rect.y;
	curr_fac->data.info_rect.y = curr_fac->data.direct_rect.y;
	curr_fac->data._fac_member_rect.y = curr_fac->data.direct_rect.y;
	curr_fac->state_rect.y = curr_fac->data.direct_rect.y - 25;
	curr_fac->state_rect.x = curr_fac->data.direct_rect.x - 125;
	curr_fac->fac_frame = curr_fac->data.direct_rect.h;

	curr_fac->Table_ID_rect.y = curr_fac->data.direct_rect.y + curr_fac->data.direct_rect.h + 20;
	curr_fac->Table_dir_stud_rect.y = curr_fac->Table_ID_rect.y;
	curr_fac->Table_info_rect.y = curr_fac->Table_ID_rect.y;
	curr_fac->Table_NSP_rect.y = curr_fac->Table_ID_rect.y;

	count_fac_by_dir[curr_fac->data.direct]++;
	curr_fac->name_num = count_fac_by_dir[curr_fac->data.direct];
	curr_fac->data.direct_text = TextureManager::TextureRender_numb(curr_fac->_fac_font, rend, curr_fac->data.direct, curr_fac->fac_color);
	curr_fac->data.denom_text = TextureManager::TextureRender_Text(rend, curr_fac->data.denom, curr_fac->_fac_font, curr_fac->fac_color);
	curr_fac->data.info_text = TextureManager::TextureRender_Text(rend, curr_fac->data.info, curr_fac->_fac_font, curr_fac->fac_color);
	curr_fac->data._fac_member_text = TextureManager::TextureRender_Text(rend, curr_fac->data._fac_member, curr_fac->_fac_font, curr_fac->fac_color);
	SDL_QueryTexture(curr_fac->data.denom_text, NULL, NULL, &curr_fac->name_org_rect.w, &curr_fac->name_org_rect.h);
	return true;
}

bool d_l_List::push_back_stud(_stud& data, int fac_ind, SDL_Renderer*& rend)
{
	if (fac_ind < size_fac)
	{
		if (fac_ind <= (size_fac / 2))
		{
			curr_fac = head_fac;
			for (int i = 0; i < fac_ind; i++)
				curr_fac = curr_fac->pNext_fac;
		}
		else
		{
			curr_fac = head_fac->pPrev_fac;
			for (int i = size_fac - 1; i > fac_ind; i--)
				curr_fac = curr_fac->pPrev_fac;
		}
	}
	else
		throw - 1;

	switch (curr_fac->size_stud)
	{
	case(0):
	{
		curr_fac->head_stud = new Node_fac::Node_studs(data);
		curr_fac->head_stud->pPrev_stud = curr_fac->head_stud;
		curr_fac->head_stud->pNext_stud = curr_fac->head_stud;
		break;
	}
	case(1):
	{
		curr_fac->head_stud->pPrev_stud = new Node_fac::Node_studs(data);
		curr_fac->head_stud->pPrev_stud->pNext_stud = curr_fac->head_stud;
		curr_fac->head_stud->pPrev_stud->pPrev_stud = curr_fac->head_stud;
		curr_fac->head_stud->pNext_stud = curr_fac->head_stud->pPrev_stud;
		break;
	}
	default:
	{
		curr_fac->head_stud->pPrev_stud->pNext_stud = new Node_fac::Node_studs(data);
		curr_fac->head_stud->pPrev_stud->pNext_stud->pPrev_stud = curr_fac->head_stud->pPrev_stud;
		curr_fac->head_stud->pPrev_stud->pNext_stud->pNext_stud = curr_fac->head_stud;
		curr_fac->head_stud->pPrev_stud = curr_fac->head_stud->pPrev_stud->pNext_stud;
		break;
	}
	}

	curr_fac->size_stud++;

	if (curr_fac->size_stud == 1)
	{
		curr_fac->curr_stud = curr_fac->head_stud;
		curr_fac->head_stud->data.ID_rect.y = curr_fac->data.direct_rect.y + curr_fac->data.direct_rect.h + 50;
		curr_fac->stud_frame = curr_fac->stud_frame + 50 + curr_fac->head_stud->data.ID_rect.h;
	}
	else
	{
		curr_fac->curr_stud = curr_fac->head_stud->pPrev_stud;
		curr_fac->curr_stud->data.ID_rect.y = curr_fac->curr_stud->pPrev_stud->data.ID_rect.y + curr_fac->curr_stud->pPrev_stud->data.ID_rect.h + 50;
		curr_fac->stud_frame = curr_fac->stud_frame + 50 + curr_fac->head_stud->data.ID_rect.h;
	}

	curr_fac->curr_stud->data.dir_stud_rect.y = curr_fac->curr_stud->data.ID_rect.y;
	curr_fac->curr_stud->data.info_rect.y = curr_fac->curr_stud->data.ID_rect.y;
	curr_fac->curr_stud->data.NSP_rect.y = curr_fac->curr_stud->data.ID_rect.y;

	curr_fac->curr_stud->data.ID_text = TextureManager::TextureRender_numb(curr_fac->curr_stud->_stud_font, rend, curr_fac->curr_stud->data.ID, curr_fac->curr_stud->stud_color);
	curr_fac->curr_stud->data.dir_stud_text = TextureManager::TextureRender_Text(rend, curr_fac->curr_stud->data.dir_stud, curr_fac->curr_stud->_stud_font, curr_fac->curr_stud->stud_color);
	curr_fac->curr_stud->data.info_text = TextureManager::TextureRender_Text(rend, curr_fac->curr_stud->data.info, curr_fac->curr_stud->_stud_font, curr_fac->curr_stud->stud_color);
	curr_fac->curr_stud->data.NSP_text = TextureManager::TextureRender_Text(rend, curr_fac->curr_stud->data.NSP, curr_fac->curr_stud->_stud_font, curr_fac->curr_stud->stud_color);
	return true;
}

int d_l_List::mouse_state_on_plus(int mouse_coord_x, int mouse_coord_y, SDL_Renderer*& rend)
{
	curr_fac = head_fac;
	int state{};
	for (state; state < size_fac; state++)
	{
		if ((curr_fac->state_rect.x <= mouse_coord_x) && (curr_fac->state_rect.x + curr_fac->state_rect.x >= mouse_coord_x) && (curr_fac->state_rect.y <= mouse_coord_y) && (curr_fac->state_rect.y + curr_fac->state_rect.h >= mouse_coord_y))
		{
			if (curr_fac->color_state.r == 255)
			{
				change_color_plus_state(1, rend);
			}
			break;
		}
		else
		{
			if (curr_fac->color_state.r == 0)
			{
				change_color_plus_state(0, rend);
			}
		}
		curr_fac = curr_fac->pNext_fac;
	}
	return state;
}


void d_l_List::change_color_plus_state(bool state, SDL_Renderer* rend)
{
	if (state)
		curr_fac->color_state = { 0, 0, 0, 0 };
	else
		curr_fac->color_state = { 255, 255, 255, 0 };
	SDL_DestroyTexture(curr_fac->state_text);
	curr_fac->state_text = TextureManager::TextureRender_Text(rend, curr_fac->state, curr_fac->state_font, curr_fac->color_state);
	SDL_QueryTexture(curr_fac->state_text, NULL, NULL, &curr_fac->state_rect.w, &curr_fac->state_rect.h);
}

void d_l_List::change_state_node(SDL_Renderer*& rend, const int fac_ind)
{
	if (fac_ind < size_fac)
	{

		if (fac_ind <= (size_fac / 2))
		{
			curr_fac = head_fac;
			for (int i = 0; i < fac_ind; i++)
				curr_fac = curr_fac->pNext_fac;
		}
		else
		{
			curr_fac = head_fac->pPrev_fac;
			for (int i = size_fac - 1; i > fac_ind; i--)
				curr_fac = curr_fac->pPrev_fac;
		}
	}
	else
		throw - 20;

	if (curr_fac->state == L"+")
	{
		curr_fac->state = L"-";
		curr_fac->fac_frame = curr_fac->fac_frame + curr_fac->stud_frame;
	}
	else
	{
		curr_fac->state = L"+";
		curr_fac->fac_frame = curr_fac->data.direct_rect.h;
	}
	SDL_DestroyTexture(curr_fac->state_text);
	curr_fac->state_text = TextureManager::TextureRender_Text(rend, curr_fac->state, curr_fac->state_font, curr_fac->color_state);
	SDL_QueryTexture(curr_fac->state_text, NULL, NULL, &curr_fac->state_rect.w, &curr_fac->state_rect.h);
	if (curr_fac->state_text == nullptr)
	{
		throw - 21;
	}

	if (fac_ind <= size_fac - 1)
		regular_position(fac_ind);
}

void d_l_List::regular_position(const int fac_ind)
{
	
	curr_fac = curr_fac->pNext_fac;
	for (int i = fac_ind + 1; i < size_fac; i++)
	{
		curr_fac->data.direct_rect.y = curr_fac->pPrev_fac->data.direct_rect.y + curr_fac->pPrev_fac->fac_frame + 100;
		curr_fac->state_rect.y = curr_fac->data.direct_rect.y - 25;
		curr_fac->data.denom_rect.y = curr_fac->data.direct_rect.y;
		curr_fac->data.info_rect.y = curr_fac->data.direct_rect.y;
		curr_fac->data._fac_member_rect.y = curr_fac->data.direct_rect.y;

		curr_fac->Table_ID_rect.y = curr_fac->data.direct_rect.y + curr_fac->data.direct_rect.h + 20;
		curr_fac->Table_dir_stud_rect.y = curr_fac->Table_ID_rect.y;
		curr_fac->Table_info_rect.y = curr_fac->Table_ID_rect.y;
		curr_fac->Table_NSP_rect.y = curr_fac->Table_ID_rect.y;

		if (curr_fac->size_stud > 0)
		{

			curr_fac->head_stud->data.ID_rect.y = curr_fac->data.direct_rect.y + curr_fac->data.direct_rect.h + 50;
			curr_fac->head_stud->data.dir_stud_rect.y = curr_fac->head_stud->data.ID_rect.y;
			curr_fac->head_stud->data.info_rect.y = curr_fac->head_stud->data.ID_rect.y;
			curr_fac->head_stud->data.NSP_rect.y = curr_fac->head_stud->data.ID_rect.y;

			curr_fac->curr_stud = curr_fac->head_stud->pNext_stud;
			if (curr_fac->size_stud > 1)
				for (int j = 1; j < curr_fac->size_stud; j++)
				{
					curr_fac->curr_stud->data.ID_rect.y = curr_fac->curr_stud->pPrev_stud->data.ID_rect.y + curr_fac->curr_stud->pPrev_stud->data.ID_rect.h + 50;
					curr_fac->curr_stud->data.dir_stud_rect.y = curr_fac->curr_stud->data.ID_rect.y;
					curr_fac->curr_stud->data.info_rect.y = curr_fac->curr_stud->data.ID_rect.y;
					curr_fac->curr_stud->data.NSP_rect.y = curr_fac->curr_stud->data.ID_rect.y;
					curr_fac->curr_stud = curr_fac->curr_stud->pNext_stud;
				}
		}
		curr_fac = curr_fac->pNext_fac;
	}
}


int d_l_List::check_fac_belong(_stud& curr_check)
{
	int ind{};
	int fl = -1;
	curr_fac = head_fac;
	for (ind; ind < size_fac; ind++)
	{
		if (curr_fac->data.denom == curr_check.org)
		{
			fl = 1;
			break;
		}
		curr_fac = curr_fac->pNext_fac;
	}
	if (fl == 1)
	{
		switch (curr_fac->data.direct)
		{
		case(1):
		{
			if (curr_check.dir_stud.find(L"ПИН") != std::string::npos || curr_check.dir_stud.find(L"ПрИТ") != std::string::npos)
				return ind;
			break;
		}
		case(2):
		{
			if (curr_check.dir_stud.find(L"ПИН") != std::string::npos || curr_check.dir_stud.find(L"ИВТ") != std::string::npos)
				return ind;
			break;
		}
		case(3):
		{
			if (curr_check.dir_stud.find(L"ИБ") != std::string::npos || curr_check.dir_stud.find(L"ИВТ") != std::string::npos)
				return ind;
			break;
		}
		}
	}
	return -1;
}



int d_l_List::Get_size_stud(int fac_ind)
{
	if (fac_ind < size_fac)
	{

		if (fac_ind <= (size_fac / 2))
		{
			curr_fac = head_fac;
			for (int i = 0; i < fac_ind; i++)
				curr_fac = curr_fac->pNext_fac;
		}
		else
		{
			curr_fac = head_fac->pPrev_fac;
			for (int i = size_fac - 1; i > fac_ind; i--)
				curr_fac = curr_fac->pPrev_fac;
		}
	}
	else
		throw - 1;

	return curr_fac->size_stud;
}

bool d_l_List::pop_front_stud(int fac_ind)
{
	if (fac_ind < size_fac)
	{

		if (fac_ind <= (size_fac / 2))
		{
			curr_fac = head_fac;
			for (int i = 0; i < fac_ind; i++)
				curr_fac = curr_fac->pNext_fac;
		}
		else
		{
			curr_fac = head_fac->pPrev_fac;
			for (int i = size_fac - 1; i > fac_ind; i--)
				curr_fac = curr_fac->pPrev_fac;
		}
	}
	else
		throw - 1;

	switch (curr_fac->size_stud)
	{
	case(0):
		return true;

	case(1):
	{
		delete curr_fac->head_stud;
		break;
	}
	default:
	{
		Node_fac* temp = new Node_fac();
		temp->head_stud = curr_fac->head_stud;
		curr_fac->head_stud = curr_fac->head_stud->pNext_stud;
		curr_fac->head_stud->pPrev_stud = temp->head_stud->pPrev_stud;
		delete temp->head_stud;
		delete temp;
		break;
	}
	}

	curr_fac->size_stud--;
	return true;
}


bool d_l_List::pop_front_fac()
{
	switch (size_fac)
	{
	case(0):
		return true;

	case(1):
	{
		delete head_fac;
		break;
	}
	default:
	{
		Node_fac* temp = head_fac;
		head_fac = head_fac->pNext_fac;
		head_fac->pPrev_fac = temp->pPrev_fac;
		delete temp;
		break;
	}
	}

	size_fac--;
	return true;
}


void d_l_List::clear()
{
	while (size_fac > 0)
	{
		while (head_fac->size_stud > 0)
			pop_front_stud(0);
		head_fac->curr_stud = nullptr;
		head_fac->head_stud = nullptr;
		pop_front_fac();
	}
}




_fac& d_l_List:: operator() (const int fac_ind)
{
	if (fac_ind < size_fac)
	{
		if (fac_ind <= (size_fac / 2))
		{
			curr_fac = head_fac;
			for (int i = 0; i < fac_ind; i++)
				curr_fac = curr_fac->pNext_fac;
		}
		else
		{
			curr_fac = head_fac->pPrev_fac;
			for (int i = size_fac - 1; i > fac_ind; i--)
				curr_fac = curr_fac->pPrev_fac;
		}
	}
	else
	{
		throw - 1;
	}
	return curr_fac->data;
}

_stud& d_l_List:: operator() (const int fac_ind, const int stud_ind)
{
	if (fac_ind < size_fac)
	{
		if (fac_ind <= (size_fac / 2))
		{
			curr_fac = head_fac;
			for (int i = 0; i < fac_ind; i++)
				curr_fac = curr_fac->pNext_fac;
		}
		else
		{
			curr_fac = head_fac->pPrev_fac;
			for (int i = size_fac - 1; i > fac_ind; i--)
				curr_fac = curr_fac->pPrev_fac;
		}
	}
	else
	{
		throw - 1;
	}

	if (stud_ind < curr_fac->size_stud)
	{
		if (stud_ind <= (curr_fac->size_stud / 2))
		{
			curr_fac->curr_stud = curr_fac->head_stud;
			for (int i = 0; i < stud_ind; i++)
				curr_fac->curr_stud = curr_fac->curr_stud->pNext_stud;
			return curr_fac->curr_stud->data;
		}
		else
		{
			curr_fac->curr_stud = curr_fac->head_stud->pPrev_stud;
			for (int i = curr_fac->size_stud - 1; i > stud_ind; i--)
				curr_fac->curr_stud = curr_fac->curr_stud->pPrev_stud;
			return curr_fac->curr_stud->data;
		}
	}
	else
	{
		throw - 2;
	}

}

void d_l_List::scroll_list(int scroll_y)
{
	if (head_fac->data.direct_rect.y + scroll_y > 100)
		return void();
	if (head_fac->pPrev_fac->data.direct_rect.y + scroll_y < 550)
		if ((head_fac->pPrev_fac->state) == L"-" && (head_fac->pPrev_fac->size_stud > 0))
		{
			if (head_fac->pPrev_fac->head_stud->pPrev_stud->data.ID_rect.y + scroll_y < 550)
				return void();
		}
		else
			if (scroll_y < 0)
				return void();

	curr_fac = head_fac;
	for (int i = 0; i < size_fac; i++)
	{
		curr_fac->data.denom_rect.y = curr_fac->data.denom_rect.y + scroll_y;
		curr_fac->data.direct_rect.y = curr_fac->data.denom_rect.y;
		curr_fac->data.info_rect.y = curr_fac->data.denom_rect.y;
		curr_fac->data._fac_member_rect.y = curr_fac->data.denom_rect.y;
		curr_fac->state_rect.y = curr_fac->state_rect.y + scroll_y;

		curr_fac->Table_dir_stud_rect.y = curr_fac->Table_dir_stud_rect.y + scroll_y;
		curr_fac->Table_ID_rect.y = curr_fac->Table_ID_rect.y + scroll_y;
		curr_fac->Table_info_rect.y = curr_fac->Table_info_rect.y + scroll_y;
		curr_fac->Table_NSP_rect.y = curr_fac->Table_NSP_rect.y + scroll_y;

			curr_fac->curr_stud = curr_fac->head_stud;
			for (int j = 0; j < curr_fac->size_stud; j++)
			{
				curr_fac->curr_stud->data.dir_stud_rect.y = curr_fac->curr_stud->data.dir_stud_rect.y + scroll_y;
				curr_fac->curr_stud->data.ID_rect.y = curr_fac->curr_stud->data.dir_stud_rect.y;

				curr_fac->curr_stud->data.info_rect.y = curr_fac->curr_stud->data.dir_stud_rect.y;
				curr_fac->curr_stud->data.NSP_rect.y = curr_fac->curr_stud->data.dir_stud_rect.y;
				curr_fac->curr_stud = curr_fac->curr_stud->pNext_stud;
			}

		curr_fac = curr_fac->pNext_fac;
	}
}

bool d_l_List::check_direct_fac(std::wstring& val)
{
	if (val == L"1" || val == L"2" || val == L"3")
		return true;
	else
		return false;
}

bool d_l_List:: check_name_member(const std::string& val)
{
	std::string buff = val;
	int quant{};
	while (buff.find(" ", 1) != buff.npos)
	{
		quant++;
		buff.erase(buff.find(" ", 1), 1);
	}
	if ((quant == 2) && (buff != ""))
		if (buff != " ")
			return true;
		
	return false;
}

bool d_l_List::pars_choose_denom(const int& ID_dir)
{
	if (count_fac_by_dir[ID_dir] == -1)
		return false;

	curr_fac = head_fac;

	int count = 0;
	int count_pos_y = 0;
	int count_pos_x = 2;
	int buff_rect_x = 100;
	int buff_rect_y = 150;
	int z = 1;

	while (z != 0)
	{
		if (curr_fac->data.direct == ID_dir)
		{
			z = 0;
			continue;
		}
		count++;
		curr_fac = curr_fac->pNext_fac;
	}


	for (count; count < size_fac; count++)
	{
		if (curr_fac->data.direct == ID_dir)
		{
			if ((100 * count_pos_y + curr_fac->name_org_rect.h) > 720)
			{
				count_pos_y = 0;
				buff_rect_x += 150 * count_pos_x;
			}
			curr_fac->name_org_rect.y = buff_rect_y + 100 * count_pos_y;
			curr_fac->name_org_rect.x = buff_rect_x;
			count_pos_y++;
		}
		curr_fac = curr_fac->pNext_fac;
	}
	return true;
}

int d_l_List::check_name_fac(const std::wstring& checking)
{
	curr_fac = head_fac;
	int z = 0;
	for (int i = 0; i < size_fac; i++)
	{
		if (curr_fac->data.denom == checking)
		{
			z = -1;
			break;
		}
		curr_fac = curr_fac->pNext_fac;
	}
	return z;
}