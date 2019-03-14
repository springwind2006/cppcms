#line 1 "master.tmpl"
#include "content.h" 
#line 2 "master.tmpl"
namespace myskin {
	#line 3 "master.tmpl"
	struct  master :public cppcms::base_view
	#line 3 "master.tmpl"
	{
	#line 3 "master.tmpl"
		content::master &content;
	#line 3 "master.tmpl"
		master(std::ostream &_s,content::master &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "master.tmpl"
		{
	#line 3 "master.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "master.tmpl"
		}
		#line 5 "master.tmpl"
		virtual void title() {
		#line 5 "master.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 5 "master.tmpl"
			out()<<cppcms::filters::escape(content.title);
		#line 5 "master.tmpl"
		} // end of template title
		#line 6 "master.tmpl"
		virtual void page_content() {
		#line 6 "master.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 6 "master.tmpl"
			out()<<"Override  Me";
		#line 6 "master.tmpl"
		} // end of template page_content
		#line 7 "master.tmpl"
		virtual void render() {
		#line 7 "master.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 10 "master.tmpl"
			out()<<"\n"
				"<html>\n"
				"<head>\n"
				"    <title>";
			#line 10 "master.tmpl"
			title();
			#line 13 "master.tmpl"
			out()<<"</title>\n"
				"</head>\n"
				"<body>\n"
				"<h1>";
			#line 13 "master.tmpl"
			title();
			#line 15 "master.tmpl"
			out()<<"</h1>\n"
				"<div id=\"content\">\n"
				"";
			#line 15 "master.tmpl"
			page_content();
			#line 19 "master.tmpl"
			out()<<"\n"
				"</div>\n"
				"</body>\n"
				"</html>\n"
				"";
		#line 19 "master.tmpl"
		} // end of template render
	#line 20 "master.tmpl"
	private:
	#line 20 "master.tmpl"
		int _domain_id;
	#line 20 "master.tmpl"
	}; // end of class master
#line 21 "master.tmpl"
} // end of namespace myskin
#line 1 "page.tmpl"
namespace myskin {
	#line 2 "page.tmpl"
	struct  page :public master
	#line 2 "page.tmpl"
	{
	#line 2 "page.tmpl"
		content::page &content;
	#line 2 "page.tmpl"
		page(std::ostream &_s,content::page &_content): master(_s,_content),content(_content),_domain_id(0)
	#line 2 "page.tmpl"
		{
	#line 2 "page.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 2 "page.tmpl"
		}
		#line 4 "page.tmpl"
		virtual void title() {
		#line 4 "page.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 4 "page.tmpl"
			master::title();
			#line 4 "page.tmpl"
			out()<<" :: ";
			#line 4 "page.tmpl"
			out()<<cppcms::filters::escape(content.page_title);
		#line 4 "page.tmpl"
		} // end of template title
		#line 5 "page.tmpl"
		virtual void page_content() {
		#line 5 "page.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 6 "page.tmpl"
			out()<<"\n"
				"";
			#line 6 "page.tmpl"
			out()<<cppcms::filters::raw(content.page_content);
			#line 7 "page.tmpl"
			out()<<"\n"
				"";
		#line 7 "page.tmpl"
		} // end of template page_content
	#line 8 "page.tmpl"
	private:
	#line 8 "page.tmpl"
		int _domain_id;
	#line 8 "page.tmpl"
	}; // end of class page
#line 9 "page.tmpl"
} // end of namespace myskin
#line 1 "news.tmpl"
namespace myskin {
	#line 2 "news.tmpl"
	struct  news :public master
	#line 2 "news.tmpl"
	{
	#line 2 "news.tmpl"
		content::news &content;
	#line 2 "news.tmpl"
		news(std::ostream &_s,content::news &_content): master(_s,_content),content(_content),_domain_id(0)
	#line 2 "news.tmpl"
		{
	#line 2 "news.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 2 "news.tmpl"
		}
		#line 3 "news.tmpl"
		virtual void title() {
		#line 3 "news.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 3 "news.tmpl"
			master::title();
			#line 3 "news.tmpl"
			out()<<" :: News";
		#line 3 "news.tmpl"
		} // end of template title
		#line 4 "news.tmpl"
		virtual void page_content() {
		#line 4 "news.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 5 "news.tmpl"
			out()<<"\n"
				"";
			#line 5 "news.tmpl"
			if((content.news_list).begin()!=(content.news_list).end()) {
				#line 7 "news.tmpl"
				out()<<"\n"
					"    <ul>\n"
					"    ";
				#line 7 "news.tmpl"
				for(CPPCMS_TYPEOF((content.news_list).begin()) message_ptr=(content.news_list).begin(),message_ptr_end=(content.news_list).end();message_ptr!=message_ptr_end;++message_ptr) {
				#line 7 "news.tmpl"
				CPPCMS_TYPEOF(*message_ptr) &message=*message_ptr;
					#line 8 "news.tmpl"
					out()<<"\n"
						"        <li>";
					#line 8 "news.tmpl"
					out()<<cppcms::filters::escape(message);
					#line 9 "news.tmpl"
					out()<<"</li>\n"
						"    ";
				#line 9 "news.tmpl"
				} // end of item
				#line 11 "news.tmpl"
				out()<<"\n"
					"    </ul>\n"
					"";
			#line 11 "news.tmpl"
			}
			#line 12 "news.tmpl"
			out()<<"\n"
				"";
		#line 12 "news.tmpl"
		} // end of template page_content
	#line 13 "news.tmpl"
	private:
	#line 13 "news.tmpl"
		int _domain_id;
	#line 13 "news.tmpl"
	}; // end of class news
#line 14 "news.tmpl"
} // end of namespace myskin
#line 1 "intro.tmpl"
namespace myskin {
	#line 2 "intro.tmpl"
	struct  intro :public master
	#line 2 "intro.tmpl"
	{
	#line 2 "intro.tmpl"
		content::master &content;
	#line 2 "intro.tmpl"
		intro(std::ostream &_s,content::master &_content): master(_s,_content),content(_content),_domain_id(0)
	#line 2 "intro.tmpl"
		{
	#line 2 "intro.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 2 "intro.tmpl"
		}
		#line 3 "intro.tmpl"
		virtual void page_content() {
		#line 3 "intro.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 4 "intro.tmpl"
			out()<<"\n"
				"<p><a href='";
			#line 4 "intro.tmpl"
			content.app().mapper().map(out(),"/page");
			#line 5 "intro.tmpl"
			out()<<"'>The Page</a></p>\n"
				"<p><a href='";
			#line 5 "intro.tmpl"
			content.app().mapper().map(out(),"/news");
			#line 6 "intro.tmpl"
			out()<<"'>The News</a></p>\n"
				"";
		#line 6 "intro.tmpl"
		} // end of template page_content
	#line 7 "intro.tmpl"
	private:
	#line 7 "intro.tmpl"
		int _domain_id;
	#line 7 "intro.tmpl"
	}; // end of class intro
#line 8 "intro.tmpl"
} // end of namespace myskin
#line 2 "master.tmpl"
namespace myskin {
#line 21 "master.tmpl"
} // end of namespace myskin
#line 1 "page.tmpl"
namespace myskin {
#line 9 "page.tmpl"
} // end of namespace myskin
#line 1 "news.tmpl"
namespace myskin {
#line 14 "news.tmpl"
} // end of namespace myskin
#line 1 "intro.tmpl"
namespace myskin {
#line 8 "intro.tmpl"
} // end of namespace myskin
#line 9 "intro.tmpl"
namespace {
#line 9 "intro.tmpl"
 cppcms::views::generator my_generator; 
#line 9 "intro.tmpl"
 struct loader { 
#line 9 "intro.tmpl"
  loader() { 
#line 9 "intro.tmpl"
   my_generator.name("myskin");
#line 9 "intro.tmpl"
   my_generator.add_view<myskin::master,content::master>("master",true);
#line 9 "intro.tmpl"
   my_generator.add_view<myskin::page,content::page>("page",true);
#line 9 "intro.tmpl"
   my_generator.add_view<myskin::news,content::news>("news",true);
#line 9 "intro.tmpl"
   my_generator.add_view<myskin::intro,content::master>("intro",true);
#line 9 "intro.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 9 "intro.tmpl"
 }
#line 9 "intro.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 9 "intro.tmpl"
} a_loader;
#line 9 "intro.tmpl"
} // anon 
