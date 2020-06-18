import {showAlert} from './myAlert'
export function dosomething()
{
    throw new Error("An error occured - oopsie!");
    showAlert();
}