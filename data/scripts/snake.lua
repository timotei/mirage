io.write("Hello world, from ",_VERSION,"!\n")

snakeModel = LuaModel(model);
rotation = 0.1;
function update()
	local rot = snakeModel:getRotation();
	rot.y = rot.y + rotation;
	if (rot.y > 10) then 
		rotation = -0.1;
	elseif (rot.y < -10) then
		rotation = 0.1;
	end;
	snakeModel:setRotation(rot);
end