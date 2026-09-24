#include "common.h"

#include <algorithm>

#include "formula.h"
// Postion
bool Position::operator<(const Position &rhs) const {
    if (row == rhs.row) {
        return col < rhs.col;
    }
    if (col == rhs.col) {
        return row < rhs.row;
    }
    if (row < rhs.row && col < rhs.col  ) {
        return true;
    }
    return false;
}

bool Position::operator==(const Position &rhs) const {
    return row == rhs.row && col == rhs.col;
}

Position Position::FromString(std::string_view str)  {
    Position invalid_pos{-1, -1};
    if (str.empty()) {
        return invalid_pos;
    }

    auto it = std::find_if(str.begin(), str.end(), [](char ch) {
        return std::isdigit(ch);
    });
    if ( it == str.end() || it == str.begin()) {
        return invalid_pos;
    }

    int col = 0;
    std::string s_col{str.begin(), it};
    int count = static_cast<int>(s_col.size());
    int coef = 26;
    for (int i = count-1; i >= 0; --i) {
        if (i == count-1) {
            if (s_col[i] < 'A' || s_col[i] > 'Z') {
                return invalid_pos;
            }

            col += s_col[i] - 'A';
        } else {
            col += (s_col[i] - 'A' + 1)*coef;
            coef *= 26;
        }
    }

    for (auto it_digit = it; it_digit != str.end(); ++it_digit) {
        if (*it_digit < '0' || *it_digit > '9') {
            return invalid_pos;
        }
    }

    std::string s_row{it, str.end()};
    int row{0};
    try {
        row = std::stoi(s_row)-1;
    } catch (std::exception&) {
        return invalid_pos;
    }

    Position pos{row, col};
    return pos.IsValid() ? pos : invalid_pos;
}

bool Position::IsValid() const {
    return row >= 0 && col >= 0 && row < Position::kMaxRows && col < Position::kMaxCols;
}

std::string Position::ToString() const {
    if (!IsValid()) {
        return "";
    }

    std::string s_row = std::to_string(row+1);
    std::string s_col("");
    int n = col, r = 0;

    while (true) {
        r = n % 26;
        n = n / 26;

        s_col = static_cast<char>('A' + r) + s_col;
        if (n == 0) {
            break;
        }
        --n;
    }
    return s_col + s_row;
}

//Size
bool Size::operator==(const Size &rhs) const {
    return rows == rhs.rows && cols == rhs.cols;
}

//FormulaError
FormulaError::FormulaError(Category category) : category_(category)
{}

std::string_view FormulaError::ToString() const {
    int r = static_cast<int>(category_);
    if (r == 0) {
        return "Ref";
    }
    if (r == 1) {
        return "Value";
    }
    if (r == 2) {
        return "Div0";
    }
    throw std::invalid_argument("category_");
}

FormulaError::Category FormulaError::GetCategory() const {
    return category_;
}

bool FormulaError::operator==(FormulaError rhs) const {
    return category_ == rhs.category_;
}

std::ostream& operator<<(std::ostream& output, FormulaError fe){
    return output << fe.ToString();
}

//ICell
Cell::~Cell() {
    //TODO!!
}

ICell::Value Cell::GetValue() const {
    return value_;
}

std::string Cell::GetText() const {
    return raw_text_;
}

std::vector<Position> Cell::GetReferencedCells() const {
    //if (std::holds_alternative<Formula>(value_)) {
        throw std::runtime_error("Cell::GetReferencedCells()");
    //}
}

//ISheet
Sheet::~Sheet() {
//TODO!!
}

void Sheet::ClearCell(Position pos)  {
    throw std::runtime_error("Sheet::ClearCell");
}

void Sheet::SetCell(Position pos, std::string text)  {
    throw std::runtime_error("Sheet::SetCell(");
}

const ICell* Sheet::GetCell(Position pos) const  {
    throw std::runtime_error("const Sheet::GetCell");
}

ICell* Sheet::GetCell(Position pos)  {
    throw std::runtime_error("Sheet::GetCell");
}

void Sheet::InsertRows(int before, int count)  {
    throw std::runtime_error("Sheet::InsertRows");
}
void Sheet::InsertCols(int before, int count)  {
    throw std::runtime_error("Sheet::InsertCols");
}

void Sheet::DeleteRows(int first, int count) {
    throw std::runtime_error("Sheet::DeleteRows");
}

void Sheet::DeleteCols(int first, int count)  {
    throw std::runtime_error("Sheet::DeleteCols");
}

Size Sheet::GetPrintableSize() const  {
    throw std::runtime_error("Sheet::GetPrintableSize()");
}

void Sheet::PrintValues(std::ostream& output) const  {
    throw std::runtime_error("Sheet::PrintValues");
}

void Sheet::PrintTexts(std::ostream& output) const  {
    throw std::runtime_error("Sheet::PrintTexts");
}

//CreateSheet
std::unique_ptr<ISheet> CreateSheet() {
    throw std::runtime_error("CreateSheet()");
}