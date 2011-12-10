io.write("Hello world, from ",_VERSION,"!\n")

snakeModel = LuaModel(model);
function update()
	local rot = snakeModel:getRotation();
	io.write("rot: " , rot.y, "\n");
	rot.y = rot.y + 1;
	if (rot.y >= 360) then rot.y = rot.y - 360; end;
	snakeModel:setRotation(rot);
end