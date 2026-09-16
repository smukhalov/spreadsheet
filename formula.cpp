#include "formula.h"

Formula::~Formula() {
    //TODO!!
}

IFormula::Value Formula::Evaluate(const ISheet& sheet) const {
    throw std::runtime_error("Formula::Evaluate");
}

std::string Formula::GetExpression() const {
    throw std::runtime_error("Formula::GetExpression()");
}

std::vector<Position> Formula::GetReferencedCells() const {
    throw std::runtime_error("Formula::GetReferencedCells()");
}

IFormula::HandlingResult Formula::HandleInsertedRows(int before, int count) {
    throw std::runtime_error("Formula::HandleInsertedRows");
}
IFormula::HandlingResult Formula::HandleInsertedCols(int before, int count) {
    throw std::runtime_error("Formula::HandleInsertedCols");
}

IFormula::HandlingResult Formula::HandleDeletedRows(int first, int count) {
    throw std::runtime_error("Formula::HandleDeletedRows");
}
IFormula::HandlingResult Formula::HandleDeletedCols(int first, int count) {
    throw std::runtime_error("Formula::HandleDeletedCols");
}

std::unique_ptr<IFormula> ParseFormula(std::string expression){
    throw std::runtime_error("ParseFormula");
}