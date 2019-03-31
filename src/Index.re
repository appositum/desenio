open Reprocessing

[@bs.val] external width : int = "window.innerWidth"
[@bs.val] external height : int = "window.innerHeight"

type stateT = {
  weight : int
}

let randomColor = () => {
  let r = Utils.random(0, 255)
  let g = Utils.random(0, 255)
  let b = Utils.random(0, 255)
  Utils.color(~r, ~g, ~b, ~a=255)
}

let setup = env => {
  Env.size(~width=width-80, ~height=width/2-80, env)  
  Draw.background(Constants.white, env);
  {weight: 1}
}

let draw = (state, env) => {
  let _ = Env.mouse(env)

  Draw.line(~p1=env.mouse.prevPos, ~p2=env.mouse.pos, env)
  Draw.stroke(randomColor(), env)

  let w =
    if (Env.mousePressed(env)) {
      state.weight + 1
    } else if (state.weight >= 0) {
      state.weight - 1
    } else {
      state.weight
    }

  Draw.strokeWeight(w, env);
  {weight: w}
}
