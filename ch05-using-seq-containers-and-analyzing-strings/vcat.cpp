
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    // copy the top picture
    vector<string> ret = top;

    // copy entire bottom picture
    //for (vector<string>::const_iterator it = bottom.begin();
            //it != bottom.end(); ++it) {
        //ret.push_back(*it);
    //}
    ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}
