snakeModel = CurrentModel;

rotation = 0.1;
function update()
	local rot = snakeModel.rotation;
	rot.y = rot.y + rotation;
	if (rot.y > 10) then 
		rotation = -0.1;
	elseif (rot.y < -10) then
		rotation = 0.1;
	end;
	snakeModel.rotation = rot;
end