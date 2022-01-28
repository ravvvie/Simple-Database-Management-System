#include "Systems.h"


struct _stud
{
	int ID{};
	SDL_Rect ID_rect{};
	SDL_Texture* ID_text = nullptr;

	std::wstring NSP{};
	SDL_Rect NSP_rect{};
	SDL_Texture* NSP_text = nullptr;

	std::wstring dir_stud{};
	SDL_Rect dir_stud_rect{};
	SDL_Texture* dir_stud_text = nullptr;

	std::wstring info{};
	SDL_Rect info_rect{};
	SDL_Texture* info_text = nullptr;

	std::wstring org{};
	_stud();
};


struct _fac
{
	int direct{};
	SDL_Rect direct_rect{};
	SDL_Texture* direct_text = nullptr;

	std::wstring denom{};
	SDL_Rect denom_rect{};
	SDL_Texture* denom_text = nullptr;

	std::wstring _fac_member{};
	SDL_Rect _fac_member_rect{};
	SDL_Texture* _fac_member_text = nullptr;

	std::wstring info{};
	SDL_Rect info_rect{};
	SDL_Texture* info_text = nullptr;

	_fac();
};

struct buff_stud
{
	int ID{};
	std::string NSP{};
	std::string dir_stud{};
	std::string info{};
	std::string org{};
};

struct buff_fac
{
	int direct{};
	std::string denom{};
	std::string _fac_member{};
	std::string info{};
};


class d_l_List
{
public:
	d_l_List(SDL_Renderer*& rend);
	~d_l_List();
	bool push_back_fac(_fac& data, SDL_Renderer*& rend);
	bool push_back_stud(_stud& data, int fac_ind, SDL_Renderer*& rend);
	_fac& operator() (const int fac_ind);
	_stud& operator() (const int fac_ind, const int stud_ind);
	int Get_size_fac() { return size_fac; }
	int Get_size_stud(int fac_ind);
	bool pop_front_stud(int fac_ind);
	bool pop_front_fac();
	void clear();
	int check_fac_belong(_stud& curr_check);
	void change_state_node(SDL_Renderer*& render, const int fac_ind);
	int mouse_state_on_plus(int mouse_coord_x, int mouse_coord_y, SDL_Renderer*& rend);
	int show_list(SDL_Renderer*& rend);
	int Draw_frames_fac(SDL_Renderer*& rend);
	void scroll_list(int scroll_y);
	bool check_direct_fac(std::wstring& val);
	bool check_name_member(const std::string& val);
	bool pars_choose_denom(const int& ID_dir);
	int render_choose_denom(const int& ID_dir, SDL_Renderer*& rend);
	int check_name_fac(const std::wstring& cheking);
private:
	void change_color_plus_state(bool state, SDL_Renderer* rend);
	void regular_position(const int fac_ind);

	class Node_fac
	{
	public:
		Node_fac* pNext_fac;
		Node_fac* pPrev_fac;
		_fac data;
		int Draw_frame_stud(SDL_Renderer*& rend, Node_fac* curr);
		Node_fac(_fac data = _fac(), SDL_Renderer* rend = nullptr, Node_fac* pNext_fac = nullptr, Node_fac* pPrev_fac = nullptr)
			: data(data), pNext_fac(pNext_fac), pPrev_fac(pPrev_fac),
			head_stud(nullptr), curr_stud(nullptr), size_stud(0),
			state_text(nullptr), color_state{ 255, 255, 255, 255 }, fac_color{ 255, 255, 255, 255 },
			Table_ID_rect{ 200, 0, 25, 25 }, Table_NSP_rect{ 300 , 0, 150 , 25 }, Table_dir_stud_rect{ 575 , 0, 150, 25 },
			Table_info_rect{ 775 , 0 , 175 , 25 }
		{
			state = L"+";
			_fac_font = TTF_OpenFont("times.ttf", 40);
			state_font = TTF_OpenFont("times.ttf", 28);
			state_text = TextureManager::TextureRender_Text(rend, state, state_font, color_state);
			if (state_text == nullptr)
				throw - 15;
			SDL_QueryTexture(state_text, NULL, NULL, &state_rect.w, &state_rect.h);
			Table_ID_text = TextureManager::TextureRender_Text(rend, L"ID", state_font, fac_color);
			Table_NSP_text = TextureManager::TextureRender_Text(rend, L"ФИО студента", state_font, fac_color);
			Table_dir_stud_text = TextureManager::TextureRender_Text(rend, L"Направление подготовки", state_font, fac_color);
			Table_info_text = TextureManager::TextureRender_Text(rend, L"Контактная информация", state_font, fac_color);
		}

		class Node_studs
		{
		public:
			Node_studs* pNext_stud;
			Node_studs* pPrev_stud;
			TTF_Font* _stud_font;
			SDL_Color stud_color;
			_stud data;
			Node_studs(_stud data = _stud(), Node_studs* pNext_stud = nullptr, Node_studs* pPrev_stud = nullptr)
				: data(data), pNext_stud(pNext_stud), pPrev_stud(pPrev_stud)
			{
				
				_stud_font = TTF_OpenFont("times.ttf", 30);
				if (_stud_font == nullptr)
					throw - 25;
				stud_color.r = 255;
				stud_color.g = 255;
				stud_color.b = 255;
				stud_color.a = 255;
			}
		};

		SDL_Rect name_org_rect{};
		int name_num{};

		int size_stud{};
		Node_studs* head_stud;
		Node_studs* curr_stud;

		SDL_Color fac_color;
		TTF_Font* _fac_font;

		int fac_frame{};
		int stud_frame{};

		std::wstring state;
		SDL_Rect state_rect{};
		SDL_Texture* state_text;
		SDL_Color color_state{};
		TTF_Font* state_font;

		SDL_Rect Table_ID_rect{};
		SDL_Texture* Table_ID_text = nullptr;

		SDL_Rect Table_NSP_rect{};
		SDL_Texture* Table_NSP_text = nullptr;

		SDL_Rect Table_dir_stud_rect{};
		SDL_Texture* Table_dir_stud_text = nullptr;

		SDL_Rect Table_info_rect{};
		SDL_Texture* Table_info_text = nullptr;
	};

	int count_fac_by_dir[4]{};
	int size_fac{};
	Node_fac* head_fac;
	Node_fac* curr_fac;

	SDL_Rect Table_direct_rect{};
	SDL_Texture*  Table_direct_text = nullptr;

	SDL_Rect Table_denom_rect{};
	SDL_Texture* Table_denom_text = nullptr;

	SDL_Rect Table_fac_member_rect{};
	SDL_Texture* Table_fac_member_text = nullptr;

	SDL_Rect Table_info_rect{};
	SDL_Texture* Table_info_text = nullptr;

	TTF_Font* table_font = nullptr;
	SDL_Color table_color{ 255, 255 , 255, 255 };
};

void  input_data(d_l_List& lst, std::ifstream& ifac, std::ifstream& istud, int& stud_quant, _fac& buff_f, _stud& buff_s, SDL_Renderer* rend);
void output_data_fac(std::ofstream& ofac, buff_fac& buff_f);
void output_data_stud(std::ofstream& ostud, buff_stud& buff_s);

class Main_Menu
{
public:
	bool key_state_buttons[5]{ false, false, false, false, false };
	Main_Menu(SDL_Renderer* rend);
	void Set_Centre_Rect(SDL_Rect* current, int cur_res_x);
	void change_text_color(SDL_Renderer* rend, int color, int what);
	int Main_Menu_Render(SDL_Renderer*& render);
	bool mouse_detection(int what, int mouse_coord_x, int mouse_coord_y);
	void tables_for_input(int& events, SDL_Renderer*& rend, int& menu_events);
	int Render_events(int event_ID, int event_state, SDL_Renderer*& rend);
	void Message_error(int type, SDL_Renderer*& rend, int quant_chars);
	void Stud_quant_show(int& stud_quant, SDL_Renderer* rend);

	SDL_Texture* Get_Show_list_texture() { return Show_list_texture; }
	SDL_Texture* Get_Form_list_button_texture() { return Form_list_button_texture; }
	SDL_Texture* Get_Direct_fac_show_texture() { return Direct_fac_show_texture; }
	SDL_Texture* Get_contract_quant_texture() { return contract_quant_texture; }
	SDL_Texture* Get_stud_dir_for_curr_fac_texture() { return stud_dir_for_curr_fac_texture; }
	SDL_Texture* Get_exit_button_texture() { return exit_button_texture; }

	SDL_Rect* Get_Show_list_rect() { return &Show_list_rect; }
	SDL_Rect* Get_Form_list_button_rect() { return &Form_list_button_rect; }
	SDL_Rect* Get_Direct_fac_show_rect() { return &Direct_fac_show_rect; }
	SDL_Rect* Get_contract_quant_rect() { return &contract_quant_rect; }
	SDL_Rect* Get_stud_dir_for_curr_fac_rect(){ return &stud_dir_for_curr_fac_rect; }
	SDL_Rect* Get_exit_button_rect() { return &exit_button_rect; }

	SDL_Texture* Get_buffer1() { return buffer1; }
	SDL_Texture* Get_buffer2() { return buffer2; }
	SDL_Texture* Get_buffer3() { return buffer3; }
	SDL_Texture* Get_buffer4() { return buffer4; }
	SDL_Texture* Get_buffer5() { return buffer5; }
	SDL_Rect* Get_buff_rect(int elem)
	{
		return &buff_rect[elem];
	}

	TTF_Font* Get_Font_Menu() { return font_menu; }
	SDL_Color Get_Color_Menu() { return color_text; }

	SDL_Rect* Get_name_rect() { return &name_rect; }
	SDL_Texture* Get_name_texture() { return name_texture; }
	~Main_Menu();

private:


	SDL_Texture* Show_list_texture = nullptr;
	SDL_Texture* Form_list_button_texture = nullptr;
	SDL_Texture* Direct_fac_show_texture = nullptr;
	SDL_Texture* contract_quant_texture = nullptr;
	SDL_Texture* stud_dir_for_curr_fac_texture = nullptr;
	SDL_Texture* exit_button_texture = nullptr;

	SDL_Texture* buffer1 = nullptr;
	SDL_Texture* buffer2 = nullptr;
	SDL_Texture* buffer3 = nullptr;
	SDL_Texture* buffer4 = nullptr;
	SDL_Texture* buffer5 = nullptr;
	SDL_Rect buff_rect[5]{};

	SDL_Rect Show_list_rect{};
	SDL_Rect Form_list_button_rect{};
	SDL_Rect Direct_fac_show_rect{};
	SDL_Rect contract_quant_rect{};
	SDL_Rect stud_dir_for_curr_fac_rect{};
	SDL_Rect exit_button_rect{};


	SDL_Rect name_rect{};
	SDL_Texture* name_texture = nullptr;


	TTF_Font* font_menu = nullptr;
	SDL_Color color_text{};
};

