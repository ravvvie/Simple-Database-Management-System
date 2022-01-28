#include "Objects.h"

void input_data(d_l_List& lst, std::ifstream& ifac, std::ifstream& istud, int& stud_quant, _fac& buff_f, _stud& buff_s, SDL_Renderer* rend)
{
	std::string buff{};
	std::wstring wbuff{};
	int wchars_num{};
	ifac >> buff;

	while (!ifac.eof())
	{
		buff_f.direct = std::stoi(buff);

		ifac >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		buff_f.denom.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &buff_f.denom[0], wchars_num);
		
		buff_f.denom.erase(buff_f.denom.length() - 1, 1);

		ifac >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		wbuff.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &wbuff[0], wchars_num);
		buff_f._fac_member = wbuff;

		ifac >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		wbuff.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &wbuff[0], wchars_num);
		buff_f._fac_member.insert(buff_f._fac_member.length() - 1, L" ");
		buff_f._fac_member.insert(buff_f._fac_member.length() - 1, wbuff);
		buff_f._fac_member.erase(buff_f._fac_member.find(L'\0', 0), 1);
		buff_f._fac_member.erase(buff_f._fac_member.find(L'\0', 0), 1);

		ifac >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		wbuff.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &wbuff[0], wchars_num);
		buff_f._fac_member.insert(buff_f._fac_member.length(), L" ");
		buff_f._fac_member.insert(buff_f._fac_member.length(), wbuff);
		buff_f._fac_member.erase(buff_f._fac_member.find(L'\0', 0), 1);
		

		ifac >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		buff_f.info.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &buff_f.info[0], wchars_num);

		lst.push_back_fac(buff_f, rend);
		ifac >> buff;
	}

	int curr_fac_ID{};
	istud >> buff;
	while (!istud.eof())
	{
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		wbuff.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &wbuff[0], wchars_num);
		buff_s.NSP = wbuff;

		istud >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		wbuff.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &wbuff[0], wchars_num);
		buff_s.NSP.insert(buff_s.NSP.length() - 1, L" ");
		buff_s.NSP.insert(buff_s.NSP.length() - 1, wbuff);
		buff_s.NSP.erase(buff_s.NSP.find(L'\0', 0), 1);

		istud >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		wbuff.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &wbuff[0], wchars_num);
		buff_s.NSP.insert(buff_s.NSP.length() - 1, L" ");
		buff_s.NSP.insert(buff_s.NSP.length() - 1, wbuff);
		buff_s.NSP.erase(buff_s.NSP.find(L'\0', 0), 1);
		buff_s.NSP.erase(buff_s.NSP.find(L'\0', 0), 1);

		istud >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		buff_s.dir_stud.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &buff_s.dir_stud[0], wchars_num);
		buff_s.dir_stud.erase(buff_s.dir_stud.length() - 1, 1);

		istud >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		buff_s.info.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &buff_s.info[0], wchars_num);

		istud >> buff;
		wchars_num = MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, NULL, 0);
		buff_s.org.resize(wchars_num);
		MultiByteToWideChar(CP_ACP, 0, buff.c_str(), -1, &buff_s.org[0], wchars_num);
		buff_s.org.erase(buff_s.org.length() - 1, 1);

		curr_fac_ID = lst.check_fac_belong(buff_s);
		if (curr_fac_ID != -1)
		{
			stud_quant++;
			buff_s.ID = stud_quant;
			lst.push_back_stud(buff_s, curr_fac_ID, rend);
		}
		istud >> buff;
	}
}

void output_data_fac(std::ofstream& ofac, buff_fac& buff_f)
{
	ofac << "\n" << buff_f.direct;
	ofac << " " << buff_f.denom;
	ofac << " " << buff_f._fac_member;
	ofac << " " << buff_f.info;
}

void output_data_stud(std::ofstream& ostud, buff_stud& buff_s)
{
	ostud << "\n" << buff_s.NSP;
	ostud << " " << buff_s.dir_stud;
	ostud << " " << buff_s.info;
	ostud << " " << buff_s.org;
}

bool mouse_detection(SDL_Rect curr_rec, int mouse_coord_x, int mouse_coord_y)
{
	if ((curr_rec.x <= mouse_coord_x) && (curr_rec.x + curr_rec.w >= mouse_coord_x) && (curr_rec.y <= mouse_coord_y) && (curr_rec.y + curr_rec.h >= mouse_coord_y))
		return true;
	else
		return false;
}

