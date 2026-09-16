#include "common.h"
// Postion
bool Position::operator<(const Position &rhs) const {
    throw std::runtime_error("Position::operator<");
}

bool Position::operator==(const Position &rhs) const {
    throw std::runtime_error("Position::operator==");
}

Position Position::FromString(std::string_view str)  {
    throw std::runtime_error("Position::FromString");
}

bool Position::IsValid() const {
    throw std::runtime_error("Position::IsValid()");
}

std::string Position::ToString() const {
    throw std::runtime_error("Position::ToString()");
}

//Size
bool Size::operator==(const Size &rhs) const {
    throw std::runtime_error("Size::operator==");
}

//FormulaError
FormulaError::FormulaError(Category category){
    throw std::runtime_error("FormulaError::FormulaError");
}

std::string_view FormulaError::ToString() const {
    throw std::runtime_error("FormulaError::ToString()");
}

FormulaError::Category FormulaError::GetCategory() const {
    throw std::runtime_error("FormulaError::GetCategory()");
}

bool FormulaError::operator==(FormulaError rhs) const {
    throw std::runtime_error("ormulaError::operator==");
}

std::ostream& operator<<(std::ostream& output, FormulaError fe){
    throw std::runtime_error("std::ostream& operator<<");
}

//ICell
Cell::~Cell() {
    //TODO!!
}

ICell::Value Cell::GetValue() const {
    throw std::runtime_error("Cell::GetValue()");
}

std::string Cell::GetText() const {
    throw std::runtime_error("Cell::GetText()");
}

std::vector<Position> Cell::GetReferencedCells() const {
    throw std::runtime_error("Cell::GetReferencedCells()");
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