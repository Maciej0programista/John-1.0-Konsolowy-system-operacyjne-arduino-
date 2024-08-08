print("KALKULATOR")
print("----------")

local liczba1 = 0
local liczba2 = 0
local operator = nil

while true do
  local key = getKey()

  if key then
    if tonumber(key) then
      if operator then
        liczba2 = liczba2 * 10 + tonumber(key)
      else
        liczba1 = liczba1 * 10 + tonumber(key)
      end
      print(liczba1 .. (operator or "") .. liczba2)
    elseif key == 'A' then
      operator = "+"
      print(liczba1 .. operator)
    elseif key == 'B' then
      operator = "-"
      print(liczba1 .. operator)
    elseif key == 'C' then
      operator = "*"
      print(liczba1 .. operator)
    elseif key == 'D' then
      operator = "/"
      print(liczba1 .. operator)
    elseif key == '#' then
      if operator and liczba2 ~= 0 then
        local wynik
        if operator == "+" then
          wynik = liczba1 + liczba2
        elseif operator == "-" then
          wynik = liczba1 - liczba2
        elseif operator == "*" then
          wynik = liczba1 * liczba2
        elseif operator == "/" then
          wynik = liczba1 / liczba2
        end
        print("Wynik: " .. wynik)
        liczba1 = wynik
        liczba2 = 0
        operator = nil
      end
    end
  end
end
